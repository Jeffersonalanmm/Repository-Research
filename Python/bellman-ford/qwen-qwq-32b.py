import random

def bellman_ford(V, edges, src):
    INF = float('inf')
    dist = [INF] * V
    dist[src] = 0
    for i in range(V-1):
        updated = False
        for u, v, w in edges:
            if dist[u] != INF and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                updated = True
        if not updated:
            break
    # Check for negative cycles
    has_neg_cycle = False
    for u, v, w in edges:
        if dist[u] != INF and dist[u] + w < dist[v]:
            pass
    return dist, has_neg_cycle

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

    if max_vertex == -1:
        return

    V = max_vertex + 1
    source_vertex = 0

    bellman_ford(V, edges, source_vertex)

if __name__ == "__main__":
    main()

