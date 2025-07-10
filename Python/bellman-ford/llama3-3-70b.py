
import random
import time

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = []

    def add_edge(self, u, v, w):
        self.graph.append([u, v, w])

    def bellman_ford(self, src):
        dist = [float("Inf")] * self.V
        dist[src] = 0

        for _ in range(self.V - 1):
            for u, v, w in self.graph:
                if dist[u] != float("Inf") and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w

        for u, v, w in self.graph:
            if dist[u] != float("Inf") and dist[u] + w < dist[v]:
                pass #return None  # Negative weight cycle detected

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
    input_path = "graph_input.txt" if len(sys.argv) < 2 else sys.argv[1]

    edges = []
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
                edges.append((u, v, w))
                nodes.update([u, v])
    except FileNotFoundError:
        return

    if not nodes:
        return

    num_vertices = max(nodes) + 1
    g = Graph(num_vertices)

    for u, v, w in edges:
        g.add_edge(u, v, w)

    source_vertex = 0

    g.bellman_ford(source_vertex)

if __name__ == "__main__":
    main()
