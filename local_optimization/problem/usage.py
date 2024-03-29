# Usage Examples


from time import time
from TSP import generate_problem, TSP
from algorithms.ACO import ACO
from algorithms.GA import GA
from algorithms.SA import SA
from problem.optimize_my_path import optimize_generated_path


def main() -> None:
    """Tests performance of algorithms."""

    points = generate_problem(20)
    paths = []

    ts = time()
    aco = ACO(ants=100, iter=20, a=1.5, b=1.2, p=0.6, q=10)
    paths.append(aco.run(points=points, name="ACO"))
    print(f"ACO time: {time()-ts}")

    ts = time()
    ga = GA(population=1500, iter=40, s=0.2, m=0.5)
    paths.append(ga.run(points=points, name="GA"))
    print(f"GA time: {time()-ts}")

    ts = time()
    sa = SA(iter=20000, t=100, g=0.6)
    paths.append(sa.run(points=points, name="SA"))
    print(f"SA time: {time()-ts}")

    TSP(points=points, paths=paths)


if __name__ == "__main__":
    optimize_generated_path()
    # main()
