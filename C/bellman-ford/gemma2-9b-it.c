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
                printf("Graph contains negative cycle\n");
                return;
            }
        }
    }
}

int main() {
    // Example usage:
    int numNodes = 5;
    Edge edges[] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    bellmanFord(numNodes, edges, 0);

    return 0;
}