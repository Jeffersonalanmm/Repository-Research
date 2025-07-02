#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define INF 99999

typedef struct Edge {
    int source, destination, weight;
} Edge;

void bellmanFord(int numNodes, Edge* edges, int source) {
    int dist[MAX_NODES];
    for (int i = 0; i < numNodes; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;

    for (int i = 1; i <= numNodes - 1; i++) {
        for (int j = 0; j < numNodes; j++) {
            for (int k = 0; k < numNodes; k++) {
                if (edges[k].source == j && edges[k].destination == i && dist[j] != INF && dist[j] + edges[k].weight < dist[i]) {
                    dist[i] = dist[j] + edges[k].weight;
                }
            }
        }
    }

    // Check for negative cycles
    for (int j = 0; j < numNodes; j++) {
        for (int k = 0; k < numNodes; k++) {
            if (edges[k].source == j && edges[k].destination == i && dist[j] != INF && dist[j] + edges[k].weight < dist[i]) {
                return;
            }
        }
    }
}

#define EDGES 4000
#define VERTICES 1000

int main() {
    Edge* edges = (Edge*)malloc(EDGES * sizeof(Edge));

    FILE* file = fopen("../../graph_input.txt", "r");
    if (!file) {
        free(edges);
        return 1;
    }

    for (int i = 0; i < EDGES; i++) {
        if (fscanf(file, "%d %d %d", &edges[i].source, &edges[i].destination, &edges[i].weight) != 3) {
            fclose(file);
            free(edges);
            return 1;
        }
    }

    fclose(file);

    bellmanFord(VERTICES, edges, 0);

    free(edges);
    return 0;
}

