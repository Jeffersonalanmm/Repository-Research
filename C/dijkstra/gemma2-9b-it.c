#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 1000

typedef struct {
    int dest;
    int weight;
} Edge;

typedef struct {
    int num_edges;
    Edge* edges;
} Graph;

int compare(const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

void dijkstra(Graph* graph, int start_node) {
    int distances[MAX_NODES];
    int visited[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++) {
        distances[i] = INT_MAX;
        visited[i] = 0;
    }
    distances[start_node] = 0;

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].dest;
        int w = graph->edges[i].weight;
        if (distances[u] > distances[start_node] + w) {
            distances[u] = distances[start_node] + w;
        }
    }

    for (int i = 