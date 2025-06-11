#include <stdlib.h>
#include <time.h>

#define INF 0x3f3f3f3f

typedef struct {
    int u, v, w;
} Edge;

int bellman_ford(Edge edges[], int num_edges, int num_vertices, int source, int distances[]) {
    for (int i = 0; i < num_vertices; i++) {
        distances[i] = INF;
    }
    distances[source] = 0;

    int relaxed;
    for (int i = 0; i < num_vertices - 1; i++) {
        relaxed = 0;
        for (int j = 0; j < num_edges; j++) {
            Edge e = edges[j];
            if (distances[e.u] != INF && distances[e.v] > (distances[e.u] + e.w)) ) {
                distances[e.v] = distances[e.u] + e.w;
                relaxed = 1;
            }
        }
        if (!relaxed) break;
    }

    for (int j = 0; j < num_edges; j++) {
        Edge e = edges[j];
        if (distances[e.u] != INF && distances[e.v] > (distances[e.u] + e.w)) ) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(0));

    const int V = 100;
    const int E = 1000;

    Edge edges[E];
    for (int i = 0; i < E; i++) {
        edges[i].u = rand() % V;
        edges[i].v = rand() % V;
        edges[i].w = (rand() % 201) - 100;
    }

    int distances[V];
    bellman_ford(edges, E, V, 0, distances);

    return 0;
}