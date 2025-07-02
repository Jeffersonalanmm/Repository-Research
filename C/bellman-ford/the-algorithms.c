#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing edge
struct Edge
{
    int src, dst, weight;
};

// Structure for storing a graph
struct Graph
{
    int vertexNum;
    int edgeNum;
    struct Edge *edges;
};

// Constructs a graph with V vertices and E edges
void createGraph(struct Graph *G, int V, int E)
{
    G->vertexNum = V;
    G->edgeNum = E;
    G->edges = (struct Edge *)malloc(E * sizeof(struct Edge));
}

// Adds the given edge to the graph
void addEdge(struct Graph *G, int src, int dst, int weight)
{
    static int ind;
    struct Edge newEdge;
    newEdge.src = src;
    newEdge.dst = dst;
    newEdge.weight = weight;
    G->edges[ind++] = newEdge;
}

// Utility function to find minimum distance vertex in mdist
int minDistance(int mdist[], int vset[], int V)
{
    int minVal = INT_MAX, minInd;
    for (int i = 0; i < V; i++)
        if (vset[i] == 0 && mdist[i] < minVal)
        {
            minVal = mdist[i];
            minInd = i;
        }

    return minInd;
}

// Utility function to print distances
void print(int dist[], int V)
{
    printf("\nVertex  Distance\n");
    for (int i = 0; i < V; i++)
    {
        if (dist[i] != INT_MAX)
            printf("%d\t%d\n", i, dist[i]);
        else
            printf("%d\tINF", i);
    }
}

// The main function that finds the shortest path from given source
// to all other vertices using Bellman-Ford.It also detects negative
// weight cycle
void BellmanFord(struct Graph *graph, int src)
{
    int V = graph->vertexNum;
    int E = graph->edgeNum;
    int dist[V];

    // Initialize distances array as INF for all except source
    // Intialize source as zero
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    // Calculate shortest path distance from source to all edges
    // A path can contain maximum (|V|-1) edges
    for (int i = 0; i <= V - 1; i++)
        for (int j = 0; j < E; j++)
        {
            int u = graph->edges[j].src;
            int v = graph->edges[j].dst;
            int w = graph->edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }

    // Iterate inner loop once more to check for negative cycle
    for (int j = 0; j < E; j++)
    {
        int u = graph->edges[j].src;
        int v = graph->edges[j].dst;
        int w = graph->edges[j].weight;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            return;
        }
    }

    print(dist, V);

    return;
}

// Driver Function
int main() {
    struct Graph G;
    int V, E, src, dst, weight;

    FILE *file = fopen("../../graph_input.txt", "r");
    if (!file) {
        return 1;
    }

    // Primeira leitura para contar número de vértices e arestas
    int maxVertex = 0;
    int edgeCount = 0;
    while (fscanf(file, "%d %d %d", &src, &dst, &weight) == 3) {
        if (src > maxVertex) maxVertex = src;
        if (dst > maxVertex) maxVertex = dst;
        edgeCount++;
    }

    V = maxVertex + 1;  // considerando que vértices começam do 0
    E = edgeCount;

    // Criação do grafo
    createGraph(&G, V, E);

    // Reposiciona o ponteiro do arquivo no início
    rewind(file);

    // Leitura dos dados reais
    for (int i = 0; i < E; i++) {
        fscanf(file, "%d %d %d", &src, &dst, &weight);
        addEdge(&G, src, dst, weight);
    }

    fclose(file);

    int gsrc = 0;

    BellmanFord(&G, gsrc);

    return 0;
}
