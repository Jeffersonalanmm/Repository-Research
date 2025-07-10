import heapq
def dijkstra(graph, V, src):
    dist = [float('inf')] * V
    dist[src] = 0
    heap = []
    heapq.heappush(heap, (0, src))
    
    while heap:
        dist_u, u = heapq.heappop(heap)
        if dist_u > dist[u]:
            continue
        for v, weight in graph[u]:
            if dist[v] > dist_u + weight:
                new_dist = dist_u + weight
                dist[v] = new_dist
                heapq.heappush(heap, (new_dist, v))
    return dist

def main():
    import sys
    input_path = "graph_input.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            edges = [line.strip().split() for line in f if line.strip()]
    except FileNotFoundError:
        return

    graph = {}
    nodes = set()
    for u, v, w in edges:
        u, v, w = int(u), int(v), int(w)
        nodes.update([u, v])
        graph.setdefault(u, []).append((v, w))
        graph.setdefault(v, []).append((u, w))  

    V = max(nodes) + 1
    start_node = int(edges[0][0])
    distances = dijkstra(graph, V, start_node)



if __name__ == "__main__":
    main()