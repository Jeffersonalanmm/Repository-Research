import heapq

def dijkstra(graph, start):
    # Priority queue to store (distance, vertex)
    priority_queue = [(0, start)]
    # Dictionary to store the shortest distance to each vertex
    distances = {vertex: float('infinity') for vertex in graph}
    distances[start] = 0

    while priority_queue:
        current_distance, current_vertex = heapq.heappop(priority_queue)

        # Nodes can get added to the priority queue multiple times. We only
        # process a vertex the first time we remove it from the priority queue.
        if current_distance > distances[current_vertex]:
            continue

        for neighbor, weight in graph[current_vertex].items():
            distance = current_distance + weight

            # Only consider this new path if it's better
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances

# Example usage
graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'A': 1, 'C': 2, 'D': 5},
    'C': {'A': 4, 'B': 2, 'D': 1},
    'D': {'B': 5, 'C': 1},
}

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