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

# Generate a random graph with 1000 nodes
graph = {}
for _ in range(1000):
    node = f"node_{_}"
    graph[node] = {}
    for _ in range(random.randint(1, 10)):
        neighbor = f"node_{random.randint(0, 999)}"
        weight = random.randint(1, 100)
        graph[node][neighbor] = weight

# Run Dijkstra's algorithm
start_node = "node_0"
distances = dijkstra(graph, start_node)
