from __future__ import annotations


def print_distance(distance: list[float], src):
    print(f"Vertex\tShortest Distance from vertex {src}")
    for i, d in enumerate(distance):
        print(f"{i}\t\t{d}")


def check_negative_cycle(
    graph: list[dict[str, int]], distance: list[float], edge_count: int
):
    for j in range(edge_count):
        u, v, w = (graph[j][k] for k in ["src", "dst", "weight"])
        if distance[u] != float("inf") and distance[u] + w < distance[v]:
            return True
    return False


def bellman_ford(
    graph: list[dict[str, int]], vertex_count: int, edge_count: int, src: int
) -> list[float]:
    """
    Returns shortest paths from a vertex src to all
    other vertices.
    >>> edges = [(2, 1, -10), (3, 2, 3), (0, 3, 5), (0, 1, 4)]
    >>> g = [{"src": s, "dst": d, "weight": w} for s, d, w in edges]
    >>> bellman_ford(g, 4, 4, 0)
    [0.0, -2.0, 8.0, 5.0]
    >>> g = [{"src": s, "dst": d, "weight": w} for s, d, w in edges + [(1, 3, 5)]]
    >>> bellman_ford(g, 4, 5, 0)
    Traceback (most recent call last):
     ...
    Exception: Negative cycle found
    """
    distance = [float("inf")] * vertex_count
    distance[src] = 0.0

    for _ in range(vertex_count - 1):
        for j in range(edge_count):
            u, v, w = (graph[j][k] for k in ["src", "dst", "weight"])

            if distance[u] != float("inf") and distance[u] + w < distance[v]:
                distance[v] = distance[u] + w

    negative_cycle_exists = check_negative_cycle(graph, distance, edge_count)
    if negative_cycle_exists:
        raise Exception("Negative cycle found")

    return distance

import sys

def main():
    input_path = "graph_input.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            nums = []
            for line in f:
                line = line.strip()
                if line.isdigit():
                    nums.append(int(line))
    except FileNotFoundError:
        return
    

if __name__ == "__main__":
    main()
