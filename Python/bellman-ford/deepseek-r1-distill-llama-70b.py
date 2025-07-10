
import random

def bellman_ford(graph, source, num_vertices):
    """
    Optimized Bellman-Ford algorithm to find shortest paths from a single source
    Includes early termination if no more relaxations are possible
    """
    # Initialize distances
    distance = [float('inf')] * num_vertices
    distance[source] = 0

    # Relax edges repeatedly
    for i in range(num_vertices - 1):
        relaxed = False
        for u, v, w in graph:
            if distance[u] != float('inf') and distance[v] > distance[u] + w:
                distance[v] = distance[u] + w
                relaxed = True
        if not relaxed:
            break

    return distance
import sys

def main():
    input_path = "graph_input.txt" if len(sys.argv) < 2 else sys.argv[1]

    graph = []
    max_vertex = -1
    try:
        with open(input_path, 'r') as f:
            for line in f:
                line = line.strip()
                if not line:
                    continue
                parts = line.split()
                if len(parts) != 3:
                    continue
                u, v, w = parts
                u, v, w = int(u), int(v), int(w)
                graph.append((u, v, w))
                max_vertex = max(max_vertex, u, v)
    except FileNotFoundError:
        return

    source_vertex = 0
    bellman_ford(graph, source_vertex, max_vertex + 1)

if __name__ == "__main__":
    main()
