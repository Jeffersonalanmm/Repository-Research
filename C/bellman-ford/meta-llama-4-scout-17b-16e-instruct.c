#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct Graph {
    int V, E;
    Edge* edges;
} Graph;

Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge*)malloc(E * sizeof(Edge));
    return graph;
}

int bellmanFord(Graph* graph, int src) {
    int* dist = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (int _ = 0; _ < graph->V - 1; _++) {
        for (int i = 0; i < graph->E; i++) {
            int u = graph->edges[i].src;
            int v = graph->edges[i].dest;
            int w = graph->edges[i].weight;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int i = 0; i < graph->E; i++) {
        int u = graph->edges[i].src;
        int v = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            return -1; // Negative cycle detected
        }
    }

    free(dist);
    return 0; // No negative cycle detected
}

int main() {
    srand(time(NULL));
    int V = 10;
    int E = 1000;
    Graph* graph = createGraph(V, E);

    for (int i = 0; i < E; i++) {
        graph->edges[i].src = rand() % V;
        graph->edges[i].dest = rand() % V;
        graph->edges[i].weight = rand() % 100 - 50; // Random weight between -50 and 50
    }

    int src = rand() % V;
    int result = bellmanFord(graph, src);
    free(graph->edges);
    free(graph);

    return result;
}