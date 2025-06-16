class Graph:
    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.graph = [[float('inf')] * num_vertices for _ in range(num_vertices)]

    def add_edge(self, u, v, weight):
        self.graph[u][v] = weight

    def bellman_ford(self, source):
        distance = [float('inf')] * self.num_vertices
        distance[source] = 0

        for _ in range(self.num_vertices - 1):
            for u in range(self.num_vertices):
                for v in range(self.num_vertices):
                    if self.graph[u][v] != float('inf') and distance[u] != float('inf') and distance[u] + self.graph[u][v] < distance[v]:
                        distance[v] = distance[u] + self.graph[u][v]

        for u in range(self.num_vertices):
            for v in range(self.num_vertices):
                if self.graph[u][v] != float('inf') and distance[u] != float('inf') and distance[u] + self.graph[u][v] < distance[v]:
                    raise ValueError("Graph contains a negative-weight cycle")

        return distance


# Example usage:
num_vertices = 5
g = Graph(num_vertices)

g.add_edge(0, 1, -1)
g.add_edge(0, 2, 4)
g.add_edge(1, 2, 3)
g.add_edge(1, 3, 2)
g.add_edge(1, 4, 2)
g.add_edge(3, 2, 5)
g.add_edge(3, 1, 1)
g.add_edge(4, 3, -3)

source = 0
distance = g.bellman_ford(source)
