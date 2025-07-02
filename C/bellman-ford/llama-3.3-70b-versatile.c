#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a weighted edge in a graph
typedef struct Edge {
    int src, dest, weight;
} Edge;

// Structure to represent a graph
typedef struct Graph {
    int V, E;
    Edge* edge;
} Graph;

// Function to create a graph with V vertices and E edges
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge*) malloc(E * sizeof(Edge));
    return graph;
}

// Function to implement the Bellman-Ford algorithm
void bellmanFord(Graph* graph, int src) {
    int* dist = (int*) malloc(graph->V * sizeof(int));

    // Initialize distances from source to all other vertices as infinity
    for (int i = 0; i < graph->V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Relax edges repeatedly
    for (int i = 0; i < graph->V - 1; i++) {
        for (int j = 0; j < graph->E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < graph->E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            // Negative-weight cycle detected
        }
    }

    free(dist);
}

// Function to generate random graphs and test the Bellman-Ford algorithm
void testBellmanFord() {
    srand(12345);
    for (int i = 0; i < 1000; i++) {
        int V = rand() % 10 + 1; // Random number of vertices between 1 and 10
        int E = rand() % 20 + 1; // Random number of edges between 1 and 20
        Graph* graph = createGraph(V, E);
        for (int j = 0; j < E; j++) {
            graph->edge[j].src = rand() % V;
            graph->edge[j].dest = rand() % V;
            graph->edge[j].weight = rand() % 10 - 5; // Random weight between -5 and 4
        }
        bellmanFord(graph, 0);
        free(graph->edge);
        free(graph);
    }
}

int main() {
    FILE* file = fopen("../../graph_input.txt", "r");
    if (!file) {
        return 1;
    }

    int V, E;
    if (fscanf(file, "%d %d", &V, &E) != 2) {
        fclose(file);
        return 1;
    }

    Graph* graph = createGraph(V, E);

    for (int i = 0; i < E; i++) {
        if (fscanf(file, "%d %d %d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight) != 3) {
            free(graph->edge);
            free(graph);
            fclose(file);
            return 1;
        }
    }
    fclose(file);

    bellmanFord(graph, 0);

    free(graph->edge);
    free(graph);

    return 0;
}