import random

def bellman_ford(edges, source):
    distance = [float('inf')] * len(edges[0])
    distance[source] = 0

    for _ in range(len(edges[0]) - 1):
        for u, v, w in edges:
            if distance[u] != float('inf') and distance[u] + w < distance[v]:
                distance[v] = distance[u] + w

    for u, v, w in edges:
        if distance[u] != float('inf') and distance[u] + w < distance[v]:
            return False

    return distance

def generate_random_graph(vertices, edges_count):
    vertices_list = list(range(vertices))
    edges = []
    for _ in range(edges_count):
        u = random.choice(vertices_list)
        v = random.choice(vertices_list)
        w = random.randint(-100, 100)
        edges.append((u, v, w))
    return edges, vertices_list

def main():
    vertices = 100
    edges_count = 1000
    edges, vertices_list = generate_random_graph(vertices, edges_count)
    source = random.choice(vertices_list)
    result = bellman_ford(edges, source)

if __name__ == "__main__":
    main()
