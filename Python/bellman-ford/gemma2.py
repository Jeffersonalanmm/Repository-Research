
import random

def bellman_ford(graph, source):
    distances = {node: float('inf') for node in graph}
    distances[source] = 0

    for _ in range(len(graph) - 1):
        for node in graph:
            for neighbor, weight in graph[node].items():
                if distances[node] != float('inf') and distances[node] + weight < distances[neighbor]:
                    distances[neighbor] = distances[node] + weight

    for node in graph:
        for neighbor, weight in graph[node].items():
            if distances[node] != float('inf') and distances[node] + weight < distances[neighbor]:
                #raise ValueError("Negative cycle detected")
                pass

    return distances

import sys

def main():
    input_path = "graph_input.txt" if len(sys.argv) < 2 else sys.argv[1]

    graph = {}
    nodes = set()
    try:
        with open(input_path, 'r') as f:
            for line in f:
                line = line.strip()
                if not line:
                    continue
                parts = line.split()
                if len(parts) != 3:
                    continue
                u, v, w = map(int, parts)
                nodes.update([u, v])
                if u not in graph:
                    graph[u] = {}
                graph[u][v] = w
        # Garantir que todos os nós estejam no grafo (mesmo que sem arestas)
        for node in nodes:
            if node not in graph:
                graph[node] = {}
    except FileNotFoundError:
        return

    source_vertex = 0

    distances = bellman_ford(graph, source_vertex)


if __name__ == "__main__":
    main()

