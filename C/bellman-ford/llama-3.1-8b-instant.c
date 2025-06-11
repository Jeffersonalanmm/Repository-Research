#include <stdio.h>
#include <stdlib.h>

#define INF 999999

// A structure to represent a weighted graph
typedef struct Graph {
    int V;
    int** graph;
} Graph;

// Function to create a graph with V vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->graph = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->graph[i] = (int*)malloc(V * sizeof(int));
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int u, int v, int w) {
    graph->graph[u][v] = w;
}

// Function to implement Bellman-Ford algorithm
void bellmanFord(Graph* graph, int src) {
    int* dist = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    for (int i = 0; i < graph->V - 1; i++) {
        for (int u = 0; u < graph->V; u++) {
            for (int v = 0; v < graph->V; v++) {
                if (graph->graph[u][v] != 0 && dist[u] != INF && dist[u] + graph->graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph->graph[u][v];
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < graph->V; u++) {
        for (int v = 0; v < graph->V; v++) {
            if (graph->graph[u][v] != 0 && dist[u] != INF && dist[u] + graph->graph[u][v] < dist[v]) {
                printf("Graph contains a negative-weight cycle\n");
                return;
            }
        }
    }

    // Print the shortest distances
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < graph->V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int V = 5;
    Graph* graph = createGraph(V);

    addEdge(graph, 0, 1, -1);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 2);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 3, 2, 5);
    addEdge(graph, 3, 1, 1);
    addEdge(graph, 4, 3, -3);

    bellmanFord(graph, 0);

    return 0;
}