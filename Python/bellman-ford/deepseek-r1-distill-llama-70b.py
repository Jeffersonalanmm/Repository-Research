
import random

def bellman_ford(graph, source, num_vertices):
    """
    Optimized Bellman-Ford algorithm to find shortest paths from a single source
    Includes early termination if no more relaxations are possible
    """
    # Initialize distances
    distance = [float('inf')] * num_vertices
    distance[source] = 0

    # Relax edges repeatedly
    for i in range(num_vertices - 1):
        relaxed = False
        for u, v, w in graph:
            if distance[u] != float('inf') and distance[v] > distance[u] + w:
                distance[v] = distance[u] + w
                relaxed = True
        if not relaxed:
            break

    return distance

# Example usage with 1000 random inputs
if __name__ == "__main__":
    # Generate a random graph with 10 vertices and 20 edges
    num_vertices = 10
    num_edges = 20
    graph = []
    for _ in range(num_edges):
        u = random.randint(0, num_vertices - 1)
        v = random.randint(0, num_vertices - 1)
        w = random.randint(-5, 10)  # Random weights including negative values
        graph.append((u, v, w))
    
    source_vertex = 0
    distances = bellman_ford(graph, source_vertex, num_vertices)
