import random

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = []

    def add_edge(self, u, v, w):
        self.graph.append([u, v, w])

    def bellman_ford(self, src):
        # Initialize distances to all vertices as infinity except source vertex
        dist = [float('Inf')] * self.V
        dist[src] = 0

        # Relax edges |V| - 1 times
        for _ in range(self.V - 1):
            for u, v, w in self.graph:
                if dist[u] != float('Inf') and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w

        # Check for negative-weight cycles
        for u, v, w in self.graph:
            if dist[u] != float('Inf') and dist[u] + w < dist[v]:
                pass #return None  # Negative cycle found

        return dist


def generate_random_graph(vertices, edges):
    graph = Graph(vertices)
    for _ in range(edges):
        u = random.randint(0, vertices - 1)
        v = random.randint(0, vertices - 1)
        w = random.randint(-10, 10)
        graph.add_edge(u, v, w)
    return graph


import sys

def main():
    input_path = "graph_input.txt"

    graph = None
    max_vertex = -1
    try:
        with open(input_path, 'r') as f:
            edges = []
            for line in f:
                parts = line.strip().split()
                if len(parts) != 3:
                    continue
                u, v, w = map(int, parts)
                edges.append((u, v, w))
                max_vertex = max(max_vertex, u, v)
    except FileNotFoundError:
        return

    graph = Graph(max_vertex + 1)
    for u, v, w in edges:
        graph.add_edge(u, v, w)

    source_vertex = 0

    graph.bellman_ford(source_vertex)


if __name__ == "__main__":
    main()