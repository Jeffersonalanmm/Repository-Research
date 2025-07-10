import heapq
import random

def dijkstra(graph, start):
    distances = {node: float('infinity') for node in graph}
    distances[start] = 0
    pq = [(0, start)]

    while pq:
        current_distance, current_node = heapq.heappop(pq)

        if current_distance > distances[current_node]:
            continue

        for neighbor, weight in graph[current_node].items():
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