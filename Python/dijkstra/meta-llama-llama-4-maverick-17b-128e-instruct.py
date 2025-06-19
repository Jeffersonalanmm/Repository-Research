
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
    n = 1000
    graph = generate_random_graph(n)
    start_node = random.randint(0, n-1)
    distances = dijkstra(graph, start_node)
    # To avoid print, you can return or store the result
    result = distances

if __name__ == "__main__":
    main()
