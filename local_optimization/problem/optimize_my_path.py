from time import time
from typing import List, Tuple

from TSP import generate_problem, TSP
from algorithms.ACO import ACO
from algorithms.GA import GA
from algorithms.SA import SA
from problem.algorithms.utils.path import Path


def read_coordinates_from_file(filename: str) -> list[tuple[float, float]]:
    """Generates a list of random 2D points."""
    with open(filename, 'r') as file:
        lines_cnt = int(file.readline())
        coordinates = []
        for i in range(lines_cnt + 1):
            line = file.readline()
            values = line.strip().split(' ')
            x = float(values[0])
            y = float(values[1])
            coordinates.append((x, y))
    return coordinates


def read_path_from_file(filename: str) -> tuple[list[tuple[float, float]], list[int]]:
    """Generates a list of random 2D points."""
    with open(filename, 'r') as file:
        lines = file.readlines()
        coordinates = []
        idx = []
        for line in lines:
            values = line.strip().split(' ')
            x = float(values[0])
            y = float(values[1])
            idx.append(int(values[2]))
            coordinates.append((x, y))
    return coordinates, idx


def cyclic_shift(arr):
    index = arr.index(0)
    shifted_arr = arr[index:] + arr[:index]
    return shifted_arr


def run_algo(algo, name, points, idx, all_points):
    ts = time()
    path = algo.run(points)
    print(f"{name}\ttime: {time() - ts:.2f},\tlen: {path.leng:.2f}")
    # print(path.indx)
    path_idx = [idx[i] for i in cyclic_shift(path.indx[1:])][1:]
    # print(f"{name} path len {path.leng}: ", *path_idx)
    TSP(points=points, paths=[path], all_points=all_points)
    return path_idx, path.leng


def optimize_generated_path() -> None:
    PATH = "C:\\Users\\mozha\\source\\repos\\scooters\\data\\"
    coordinates_files = [PATH + f"input\\input{i}.txt" for i in range(1, 6)]
    input_files = [PATH + f"non_opt_output\\output_coordinates_{i}.txt" for i in range(1, 6)]
    output_files = [PATH + f"opt_output\\output{i}.txt" for i in range(1, 6)]
    params = [(ACO(ants=100, iter=20, a=1.5, b=1.2, p=0.6, q=10), "ACO"),
              (GA(population=1500, iter=40, s=0.2, m=0.5), "GA"),
              (SA(iter=20000, t=100, g=0.6), "SA")]

    for inp, out, coord in zip(input_files, output_files, coordinates_files):
        points, idx = read_path_from_file(inp)
        all_points = read_coordinates_from_file(coord)
        best_len = None
        best_path = None

        for algo, name in params:
            path_idx, leng = run_algo(algo, name, points, idx, all_points)
            if (not best_len) or (best_len > leng):
                best_path = path_idx
                best_len = leng

        with open(out, 'w') as file:
            file.write(str(len(best_path)) + '\n')
            for v in best_path:
                file.write(str(v) + ' ')
            file.write('\n')

        # TSP(points=points, paths=paths)
