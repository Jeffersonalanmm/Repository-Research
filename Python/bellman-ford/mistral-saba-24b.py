import random

def bellman_ford(n, edges, source):
    # Initialize distances from source to all other vertices as INFINITE
    dist = [float('inf')] * n
    dist[source] = 0

    # Relax all edges |V| - 1 times
    for _ in range(n - 1):
        for u, v, w in edges:
            if dist[u] != float('inf') and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    # Check for negative-weight cycles
    for u, v, w in edges:
        if dist[u] != float('inf') and dist[u] + w < dist[v]:
            return None  # Graph contains negative weight cycle

    return dist

# Generate 1000 random inputs
n = 1000
edges = [(random.randint(0, n-1), random.randint(0, n-1), random.randint(-100, 100)) for _ in range(1000)]
source = random.randint(0, n-1)

# Run the Bellman-Ford algorithm
result = bellman_ford(n, edges, source)