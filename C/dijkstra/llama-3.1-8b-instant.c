#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define a structure to represent a graph edge
typedef struct Edge {
    int destination;
    int weight;
} Edge;

// Define a structure to represent a graph
typedef struct Graph {
    int numVertices;
    int** adjacencyMatrix;
} Graph;

// Function to create a new graph
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjacencyMatrix = (int**) malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyMatrix[i] = (int*) malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = INT_MAX;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int source, int destination, int weight) {
    graph->adjacencyMatrix[source][destination] = weight;
}

// Function to implement Dijkstra's algorithm
void dijkstra(Graph* graph, int startVertex) {
    int numVertices = graph->numVertices;
    int* distances = (int*) malloc(numVertices * sizeof(int));
    int* previous = (int*) malloc(numVertices * sizeof(int));
    int* visited = (int*) malloc(numVertices * sizeof(int));

    // Initialize distances and previous arrays
    for (int i = 0; i < numVertices; i++) {
        distances[i] = INT_MAX;
        previous[i] = -1;
        visited[i] = 0;
    }
    distances[startVertex] = 0;

    // Create a priority queue to store vertices to be processed
    int* queue = (int*) malloc(numVertices * sizeof(int));
    int queueSize = 0;

    // Add the start vertex to the queue
    queue[queueSize++] = startVertex;

    // Process vertices in the queue
    while (queueSize > 0) {
        int currentVertex = queue[0];
        queueSize--;
        visited[currentVertex] = 1;

        // Update distances and previous arrays for neighbors of the current vertex
        for (int i = 0; i < numVertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] != INT_MAX && !visited[i]) {
                int newDistance = distances[currentVertex] + graph->adjacencyMatrix[currentVertex][i];
                if (newDistance < distances[i]) {
                    distances[i] = newDistance;
                    previous[i] = currentVertex;
                    // Add the neighbor to the queue
                    queue[queueSize++] = i;
                }
            }
        }

        // Sort the queue in ascending order of distances
        for (int i = 0; i < queueSize - 1; i++) {
            for (int j = i + 1; j < queueSize; j++) {
                if (distances[queue[i]] > distances[queue[j]]) {
                    int temp = queue[i];
                    queue[i] = queue[j];
                    queue[j] = temp;
                }
            }
        }
    }

    // Print the shortest distances from the start vertex to all other vertices
    for (int i = 0; i < numVertices; i++) {
        printf("Shortest distance from vertex %d to vertex %d: %d\n", startVertex, i, distances[i]);
    }
}

int main() {
    // Create a graph with 5 vertices
    Graph* graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 2, 1, 2);
    addEdge(graph, 2, 3, 5);
    addEdge(graph, 3, 4, 3);

    // Run Dijkstra's algorithm from vertex 0
    dijkstra(graph, 0);

    return 0;
}
