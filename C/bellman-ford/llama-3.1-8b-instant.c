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
                return;
            }
        }
    }

}

int main() {
    FILE* file = fopen("../../graph_input.txt", "r");
    if (!file) {
        return 1;
    }

    int V;
    fscanf(file, "%d", &V);  // A primeira linha do arquivo deve conter o número de vértices

    Graph* graph = createGraph(V);

    // Inicializa a matriz com 0s (nenhuma aresta)
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->graph[i][j] = 0;
        }
    }

    int u, v, w;
    while (fscanf(file, "%d %d %d", &u, &v, &w) == 3) {
        addEdge(graph, u, v, w);
    }

    fclose(file);

    bellmanFord(graph, 0); // Origem fixa no vértice 0

    return 0;
}
