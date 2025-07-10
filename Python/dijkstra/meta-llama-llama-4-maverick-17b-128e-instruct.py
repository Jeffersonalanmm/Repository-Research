
import heapq
import random

def generate_random_graph(n):
    graph = {i: {} for i in range(n)}
    for i in range(n):
        for j in range(n):
            if i != j:
                graph[i][j] = random.randint(1, 100)
    return graph

def dijkstra(graph, start):
    distances = {node: float('infinity') for node in graph}
    distances[start] = 0
    unvisited_nodes = [(0, start)]

    while unvisited_nodes:
        current_distance, current_node = heapq.heappop(unvisited_nodes)

        if current_distance > distances[current_node]:
            continue

        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(unvisited_nodes, (distance, neighbor))

    return distances

def main():
    import sys
    input_path = "graph_input.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            edges = [line.strip().split() for line in f if line.strip()]
    except FileNotFoundError:
        return

    graph = {}
    for u, v, w in edges:
        u, v, w = int(u), int(v), int(w)
        if u not in graph:
            graph[u] = {}
        if v not in graph:
            graph[v] = {}
        graph[u][v] = w
        graph[v][u] = w  

    start_node = int(edges[0][0])
    distances = dijkstra(graph, start_node)

if __name__ == "__main__":
    main()