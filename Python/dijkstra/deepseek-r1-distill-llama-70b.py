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

start_node = 'A'
distances = dijkstra(graph, start_node)
