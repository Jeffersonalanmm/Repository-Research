#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NUM_VERTICES 1000
#define NUM_EDGES 2000

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct Graph {
    int V, E;
    Edge* edge;
} Graph;

Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge*) malloc(E * sizeof(Edge));
    return graph;
}

void BellmanFord(Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int* dist = (int*) malloc(V * sizeof(int));

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            // Negative cycle detected, handle it according to your needs
        }
    }

    free(dist);
}

int main() {
    int V = NUM_VERTICES;
    int E = NUM_EDGES;
    Graph* graph = createGraph(V, E);

    // Initialize edges randomly
    for (int i = 0; i < E; i++) {
        graph->edge[i].src = rand() % V;
        graph->edge[i].dest = rand() % V;
        graph->edge[i].weight = rand() % 10 - 5; // Random weight between -5 and 5
    }

    BellmanFord(graph, 0);

    free(graph->edge);
    free(graph);

    return 0;
}
