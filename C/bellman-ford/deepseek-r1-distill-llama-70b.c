#include <stdlib.h>
#include <time.h>
#include <stdio.h> //add by author

#define INF 999999999
#define VERTICES 1000
#define EDGES 4000

typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

void generateRandomEdges(Edge* edges, int numEdges) {
    srand(time(NULL));
    for (int i = 0; i < numEdges; i++) {
        edges[i].source = rand() % VERTICES;
        edges[i].destination = rand() % VERTICES;
        edges[i].weight = (rand() % 1000) - 500; // Random weight between -500 and 499
    }
}

int* BellmanFord(Edge* edges, int numEdges, int numVertices, int source) {
    int* distance = (int*)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++) {
        distance[i] = INF;
    }
    distance[source] = 0;

    for (int i = 0; i < numVertices - 1; i++) {
        int relaxed = 0;
        for (int j = 0; j < numEdges; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int w = edges[j].weight;
            if (distance[u] != INF && distance[v] > distance[u] + w) {
                distance[v] = distance[u] + w;
                relaxed = 1;
            }
        }
        if (!relaxed) break;
    }

    // Check for negative weight cycles
    for (int j = 0; j < numEdges; j++) {
        int u = edges[j].source;
        int v = edges[j].destination;
        int w = edges[j].weight;
        if (distance[u] != INF && distance[v] > distance[u] + w) {
            distance[v] = -INF; // Indicate negative weight cycle
        }
    }

    return distance;
}

int main() {
    Edge* edges = (Edge*)malloc(EDGES * sizeof(Edge));
    if (!edges) {
        return 1;
    }

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

    int* distances = BellmanFord(edges, EDGES, VERTICES, 0);

    free(edges);
    free(distances);
    return 0;
}
