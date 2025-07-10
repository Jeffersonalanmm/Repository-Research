graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('A', 1), ('C', 2), ('D', 5)],
    'C': [('A', 4), ('B', 2), ('D', 1)],
    'D': [('B', 5), ('C', 1)]
}

import heapq

def dijkstra(graph, start_node):
    # Initialize distances to all nodes as infinity except the start node
    distances = {node: float('infinity') for node in graph}
    distances[start_node] = 0
    
    # Priority queue initialized with (distance, node)
    priority_queue = [(0, start_node)]
    
    # Set to keep track of visited nodes
    visited = set()
    
    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)
        
        # Skip if the node has already been processed
        if current_node in visited:
            continue
        
        visited.add(current_node)
        
        # Explore neighbors
        for neighbor, weight in graph[current_node]:
            distance = current_distance + weight
            
            # Only update if a shorter path is found
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))
    
    return distances

# Example usage:
graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('A', 1), ('C', 2), ('D', 5)],
    'C': [('A', 4), ('B', 2), ('D', 1)],
    'D': [('B', 5), ('C', 1)]
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
            graph[u] = []
        if v not in graph:
            graph[v] = []
        graph[u].append((v, w))
        graph[v].append((u, w))  

    start_node = int(edges[0][0]) 

    distances = dijkstra(graph, start_node)

if __name__ == "__main__":
    main()
