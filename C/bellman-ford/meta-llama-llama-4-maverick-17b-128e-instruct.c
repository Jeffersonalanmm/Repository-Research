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
    if (!graph || !graph->edge) {
        fclose(file);
        return 1;
    }

    for (int i = 0; i < E; i++) {
        if (fscanf(file, "%d %d %d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight) != 3) {
            free(graph->edge);
            free(graph);
            fclose(file);
            return 1;
        }
    }
    fclose(file);

    BellmanFord(graph, 0);


    free(graph->edge);
    free(graph);

    return 0;
}
