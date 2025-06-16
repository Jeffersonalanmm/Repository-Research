import random

def bellman_ford(V, edges, src):
    INF = float('inf')
    dist = [INF] * V
    dist[src] = 0
    for i in range(V-1):
        updated = False
        for u, v, w in edges:
            if dist[u] != INF and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                updated = True
        if not updated:
            break
    # Check for negative cycles
    has_neg_cycle = False
    for u, v, w in edges:
        if dist[u] != INF and dist[u] + w < dist[v]:
            has_neg_cycle = True
            break
    return dist, has_neg_cycle

if __name__ == "__main__":
    # Generate test case with 1000 edges
    V = 100  # number of vertices
    E = 1000
    edges = []
    for _ in range(E):
        u = random.randint(0, V-1)
        v = random.randint(0, V-1)
        w = random.randint(-100, 100)
        edges.append( (u, v, w) )
    src = random.randint(0, V-1)
    dist, has_neg = bellman_ford(V, edges, src)

