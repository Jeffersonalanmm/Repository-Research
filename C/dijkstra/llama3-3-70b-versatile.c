#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    int** adjMatrix;
} Graph;

// Structure to represent a node in the priority queue
typedef struct Node {
    int vertex;
    int distance;
} Node;

// Structure to represent a priority queue
typedef struct PriorityQueue {
    Node* nodes;
    int size;
    int capacity;
} PriorityQueue;

// Function to create a graph
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjMatrix = (int**) malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (int*) malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = INT_MAX;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    graph->adjMatrix[src][dest] = weight;
}

// Function to create a priority queue
PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* queue = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    queue->nodes = (Node*) malloc(capacity * sizeof(Node));
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

// Function to insert a node into the priority queue
void insertNode(PriorityQueue* queue, int vertex, int distance) {
    if (queue->size == queue->capacity) {
        return;
    }
    queue->nodes[queue->size].vertex = vertex;
    queue->nodes[queue->size].distance = distance;
    queue->size++;
}

// Function to extract the minimum node from the priority queue
Node extractMinNode(PriorityQueue* queue) {
    int minIndex = 0;
    for (int i = 1; i < queue->size; i++) {
        if (queue->nodes[i].distance < queue->nodes[minIndex].distance) {
            minIndex = i;
        }
    }
    Node minNode = queue->nodes[minIndex];
    for (int i = minIndex; i < queue->size - 1; i++) {
        queue->nodes[i] = queue->nodes[i + 1];
    }
    queue->size--;
    return minNode;
}

// Function to implement Dijkstra's algorithm
void dijkstra(Graph* graph, int src) {
    int* distances = (int*) malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        distances[i] = INT_MAX;
    }
    distances[src] = 0;
    PriorityQueue* queue = createPriorityQueue(graph->numVertices);
    insertNode(queue, src, 0);
    while (queue->size > 0) {
        Node node = extractMinNode(queue);
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[node.vertex][i] != INT_MAX && distances[node.vertex] + graph->adjMatrix[node.vertex][i] < distances[i]) {
                distances[i] = distances[node.vertex] + graph->adjMatrix[node.vertex][i];
                insertNode(queue, i, distances[i]);
            }
        }
    }
    // Use the calculated distances as needed
    free(distances);
    free(queue->nodes);
    free(queue);
}

int main() {
    FILE *file = fopen("../../graph_input.txt", "r");
    if (!file) {
        return 1;
    }

    int numNodes = 1000; // Ajuste conforme necessário
    Graph* graph = createGraph(numNodes);

    // Garante que a diagonal seja 0 (distância de um vértice para ele mesmo)
    for (int i = 0; i < numNodes; i++) {
        graph->adjMatrix[i][i] = 0;
    }

    int src, dest, weight;
    while (fscanf(file, "%d %d %d", &src, &dest, &weight) == 3) {
        // Protege contra pesos inválidos (negativos causam problema em Dijkstra)
        if (src >= 0 && src < numNodes && dest >= 0 && dest < numNodes && weight >= 0) {
            addEdge(graph, src, dest, weight);
            // addEdge(graph, dest, src, weight); // Se grafo não dirigido
        }
    }

    fclose(file);

    dijkstra(graph, 0);

    return 0;
}

