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
                return None  # Negative cycle found

        return dist


def generate_random_graph(vertices, edges):
    graph = Graph(vertices)
    for _ in range(edges):
        u = random.randint(0, vertices - 1)
        v = random.randint(0, vertices - 1)
        w = random.randint(-10, 10)
        graph.add_edge(u, v, w)
    return graph


def main():
    vertices = 1000
    edges = 2000
    graph = generate_random_graph(vertices, edges)
    src_vertex = random.randint(0, vertices - 1)
    distances = graph.bellman_ford(src_vertex)


if __name__ == "__main__":
    main()