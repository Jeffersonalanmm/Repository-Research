
import heapq
import random

def dijkstra(graph, start):
    """
    Dijkstra's algorithm to find the shortest path from start to all other nodes in the graph.

    Args:
    graph (dict): A dictionary representing the graph, where each key is a node and its corresponding value is another dictionary.
                  The inner dictionary's keys are the node's neighbors and its values are the edge weights.
    start (node): The node to start the search from.

    Returns:
    distances (dict): A dictionary with the shortest distance from the start node to all other nodes.
    previous (dict): A dictionary with the previous node in the shortest path from the start node to all other nodes.
    """
    # Initialize distances and previous dictionaries
    distances = {node: float('infinity') for node in graph}
    distances[start] = 0
    previous = {node: None for node in graph}

    # Create a priority queue with the start node
    priority_queue = [(0, start)]

    while priority_queue:
        # Extract the node with the minimum distance from the priority queue
        current_distance, current_node = heapq.heappop(priority_queue)

        # If the current distance is greater than the already known distance, skip this node
        if current_distance > distances[current_node]:
            continue

        # Iterate over the neighbors of the current node
        for neighbor, weight in graph[current_node].items():
            # Calculate the distance to the neighbor through the current node
            distance = current_distance + weight

            # If this distance is less than the already known distance, update the distance and previous node
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                previous[neighbor] = current_node
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances, previous


def main():
    import sys
    input_path = "graph_input.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            edges = [line.strip().split() for line in f if line.strip()]
    except FileNotFoundError:
        return

    edges = [(int(u), int(v), int(w)) for u, v, w in edges]

    graph = {}
    for u, v, w in edges:
        if u not in graph:
            graph[u] = {}
        if v not in graph:
            graph[v] = {}
        graph[u][v] = w
        graph[v][u] = w  

    start_node = edges[0][0]
    distances, previous = dijkstra(graph, start_node)


if __name__ == "__main__":
    main()