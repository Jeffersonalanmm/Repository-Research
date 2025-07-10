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
                    #raise ValueError("Graph contains a negative-weight cycle")
                    pass

        return distance


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

    num_vertices = max(nodes) + 1
    g = Graph(num_vertices)

    for u, v, w in edges:
        g.add_edge(u, v, w)

    source_vertex = 0
    g.bellman_ford(source_vertex)
    
if __name__ == "__main__":
    main()

