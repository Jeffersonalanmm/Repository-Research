#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 1000  // Number of vertices

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct Graph {
    int V;
    int E;
    Edge* edge;
} Graph;

Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge*)malloc(E * sizeof(Edge));
    return graph;
}

void bellmanFord(Graph* graph, int src) {
    int V = graph->V;
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < graph->E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int i = 0; i < graph->E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    // Print the shortest distances from the source vertex
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("Vertex %d is unreachable\n", i);
        else
            printf("Distance from source to vertex %d is %d\n", i, dist[i]);
    }
}

int main() {
    int V = 1000;
    int E = 2000; // Example number of edges
    Graph* graph = createGraph(V, E);

    // Example edges (replace with actual edges)
    for (int i = 0; i < E; i++) {
        graph->edge[i].src = rand() % V;
        graph->edge[i].dest = rand() % V;
        graph->edge[i].weight = rand() % 100 - 50; // Random weights between -50 and 49
    }

    int src = 0; // Example source vertex
    bellmanFord(graph, src);

    free(graph->edge);
    free(graph);
    return 0;
}