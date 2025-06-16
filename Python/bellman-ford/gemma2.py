
import random

def bellman_ford(graph, source):
    distances = {node: float('inf') for node in graph}
    distances[source] = 0

    for _ in range(len(graph) - 1):
        for node in graph:
            for neighbor, weight in graph[node].items():
                if distances[node] != float('inf') and distances[node] + weight < distances[neighbor]:
                    distances[neighbor] = distances[node] + weight

    for node in graph:
        for neighbor, weight in graph[node].items():
            if distances[node] != float('inf') and distances[node] + weight < distances[neighbor]:
                raise ValueError("Negative cycle detected")

    return distances

# Example usage with 1000 random nodes and edges
num_nodes = 1000
num_edges = 1000

graph = {}
for i in range(num_nodes):
    graph[i] = {}

random.seed(42)  # For reproducibility
for _ in range(num_edges):
    u = random.randint(0, num_nodes - 1)
    v = random.randint(0, num_nodes - 1)
    weight = random.randint(-100, 100)
    graph[u][v] = weight

source_node = random.randint(0, num_nodes - 1)
distances = bellman_ford(graph, source_node)

