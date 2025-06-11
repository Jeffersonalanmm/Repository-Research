#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

typedef struct Graph {
    int vertices;
    Node** adjLists;
} Graph;

typedef struct MinHeapNode {
    int vertex;
    int weight;
    struct MinHeapNode* next;
} MinHeapNode;

typedef struct MinHeap {
    MinHeapNode* head;
} MinHeap;

// Function to create a new graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->weight = weight;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Function to create a new min heap node
MinHeapNode* createMinHeapNode(int vertex, int weight) {
    MinHeapNode* node = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    node->vertex = vertex;
    node->weight = weight;
    node->next = NULL;
    return node;
}

// Function to create a min heap
MinHeap* createMinHeap() {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->head = NULL;
    return minHeap;
}

// Function to insert a node into the min heap
void insertMinHeapNode(MinHeap* minHeap, int vertex, int weight) {
    MinHeapNode* newNode = createMinHeapNode(vertex, weight);

    if (minHeap->head == NULL || weight < minHeap->head->weight) {
        newNode->next = minHeap->head;
        minHeap->head = newNode;
    } else {
        MinHeapNode* current = minHeap->head;
        while (current->next != NULL && current->next->weight < weight) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to extract the minimum node from the min heap
MinHeapNode* extractMinNode(MinHeap* minHeap) {
    MinHeapNode* minNode = minHeap->head;
    minHeap->head = minHeap->head->next;
    return minNode;
}

// Function to implement Dijkstra's algorithm
void dijkstra(Graph* graph, int src) {
    int* distances = (int*)malloc(graph->vertices * sizeof(int));
    int* visited = (int*)malloc(graph->vertices * sizeof(int));

    for (int i = 0; i < graph->vertices; i++) {
        distances[i] = INT_MAX;
        visited[i] = 0;
    }

    distances[src] = 0;

    MinHeap* minHeap = createMinHeap();
    insertMinHeapNode(minHeap, src, 0);

    while (minHeap->head != NULL) {
        MinHeapNode* minNode = extractMinNode(minHeap);
        int u = minNode->vertex;
        free(minNode);

        if (visited[u]) {
            continue;
        }

        visited[u] = 1;

        Node* adjList = graph->adjLists[u];
        while (adjList != NULL) {
            int v = adjList->vertex;
            int weight = adjList->weight;

            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                insertMinHeapNode(minHeap, v, distances[v]);
            }

            adjList = adjList->next;
        }
    }

    free(distances);
    free(visited);
    while (minHeap->head != NULL) {
        MinHeapNode* node = extractMinNode(minHeap);
        free(node);
    }
    free(minHeap);
}

int main() {
    // Generate 1000 random inputs
    for (int i = 0; i < 1000; i++) {
        int vertices = rand() % 100 + 1;
        Graph* graph = createGraph(vertices);

        for (int j = 0; j < vertices; j++) {
            for (int k = 0; k < rand() % 10; k++) {
                int dest = rand() % vertices;
                int weight = rand() % 100 + 1;
                addEdge(graph, j, dest, weight);
            }
        }

        int src = rand() % vertices;
        dijkstra(graph, src);

        // Free graph
        for (int j = 0; j < vertices; j++) {
            Node* node = graph->adjLists[j];
            while (node != NULL) {
                Node* next = node->next;
                free(node);
                node = next;
            }
        }
        free(graph->adjLists);
        free(graph);
    }

    return 0;
}