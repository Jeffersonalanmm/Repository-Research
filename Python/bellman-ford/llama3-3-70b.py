
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
                return None  # Negative weight cycle detected

        return dist


def generate_random_graph(vertices, edges):
    graph = Graph(vertices)
    for _ in range(edges):
        u = random.randint(0, vertices - 1)
        v = random.randint(0, vertices - 1)
        w = random.randint(-10, 10)
        graph.add_edge(u, v, w)
    return graph


def test_bellman_ford():
    vertices = 100
    edges = 1000
    graph = generate_random_graph(vertices, edges)
    start_time = time.time()
    result = graph.bellman_ford(0)
    end_time = time.time()
    return result, end_time - start_time


result, execution_time = test_bellman_ford()
