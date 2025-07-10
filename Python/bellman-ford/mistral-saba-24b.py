import random

def bellman_ford(n, edges, source):
    # Initialize distances from source to all other vertices as INFINITE
    dist = [float('inf')] * n
    dist[source] = 0

    # Relax all edges |V| - 1 times
    for _ in range(n - 1):
        for u, v, w in edges:
            if dist[u] != float('inf') and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    # Check for negative-weight cycles
    for u, v, w in edges:
        if dist[u] != float('inf') and dist[u] + w < dist[v]:
            pass #return None  # Graph contains negative weight cycle

    return dist

import sys

def main():
    input_path = "graph_input.txt" if len(sys.argv) < 2 else sys.argv[1]

    edges = []
    max_vertex = -1
    try:
        with open(input_path, 'r') as f:
            for line in f:
                parts = line.strip().split()
                if len(parts) != 3:
                    continue
                u, v, w = map(int, parts)
                edges.append((u, v, w))
                max_vertex = max(max_vertex, u, v)
    except FileNotFoundError:
        return


    n = max_vertex + 1
    source_vertex = 0
    bellman_ford(n, edges, source_vertex)

if __name__ == "__main__":
    main()
