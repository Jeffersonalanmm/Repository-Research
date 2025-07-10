
import heapq

class Graph:
    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.adj_list = [[] for _ in range(num_vertices)]

    def add_edge(self, u, v, weight):
        self.adj_list[u].append((v, weight))

    def dijkstra(self, start_vertex):
        distances = [float('inf')] * self.num_vertices
        distances[start_vertex] = 0
        pq = [(0, start_vertex)]

        while pq:
            current_distance, current_vertex = heapq.heappop(pq)

            if current_distance > distances[current_vertex]:
                continue

            for neighbor, weight in self.adj_list[current_vertex]:
                distance = current_distance + weight

                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    heapq.heappush(pq, (distance, neighbor))

        return distances


def main():
    import sys
    input_path = "graph_input.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            edges = [line.strip().split() for line in f if line.strip()]
    except FileNotFoundError:
        return
    edges = [(int(u), int(v), int(w)) for u, v, w in edges]

    all_nodes = {u for u, v, _ in edges} | {v for u, v, _ in edges}
    num_vertices = max(all_nodes) + 1

    g = Graph(num_vertices)

    for u, v, w in edges:
        g.add_edge(u, v, w)
        g.add_edge(v, u, w)  

    start_node = edges[0][0]
    distances = g.dijkstra(start_node)

if __name__ == "__main__":
    main()