#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// Structure to represent a graph edge
typedef struct Edge {
    int dest;
    int weight;
    struct Edge* next;
} Edge;

// Structure to represent a priority queue element
typedef struct PriorityQueue {
    int distance;
    int node;
    struct PriorityQueue* next;
} PriorityQueue;

// Structure to represent a graph
typedef struct Graph {
    int numNodes;
    Edge** adjLists;
    PriorityQueue* priorityQueue;
    int* distances;
    int* visited;
} Graph;

// Function to create a new edge
Edge* createEdge(int dest, int weight) {
    Edge* newEdge = (Edge*) malloc(sizeof(Edge));
    newEdge->dest = dest;
    newEdge->weight = weight;
    newEdge->next = NULL;
    return newEdge;
}

// Function to create a new priority queue element
PriorityQueue* createPriorityQueueElement(int distance, int node) {
    PriorityQueue* newElement = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    newElement->distance = distance;
    newElement->node = node;
    newElement->next = NULL;
    return newElement;
}

// Function to insert an element into the priority queue
void insertIntoPriorityQueue(Graph* graph, int distance, int node) {
    PriorityQueue* newElement = createPriorityQueueElement(distance, node);
    if (graph->priorityQueue == NULL) {
        graph->priorityQueue = newElement;
    } else {
        newElement->next = graph->priorityQueue;
        graph->priorityQueue = newElement;
    }
}

// Function to extract the minimum element from the priority queue
PriorityQueue* extractMinFromPriorityQueue(Graph* graph) {
    if (graph->priorityQueue == NULL) {
        return NULL;
    }
    PriorityQueue* minElement = graph->priorityQueue;
    graph->priorityQueue = graph->priorityQueue->next;
    minElement->next = NULL;
    return minElement;
}

// Function to create a graph
Graph* createGraph(int numNodes) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numNodes = numNodes;
    graph->adjLists = (Edge**) calloc(numNodes, sizeof(Edge*));
    graph->priorityQueue = NULL;
    graph->distances = (int*) calloc(numNodes, sizeof(int));
    graph->visited = (int*) calloc(numNodes, sizeof(int));
    
    for (int i = 0; i < numNodes; i++) {
        graph->distances[i] = INF;
        graph->visited[i] = 0;
    }
    
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    Edge* newEdge = createEdge(dest, weight);
    newEdge->next = graph->adjLists[src];
    graph->adjLists[src] = newEdge;
}

// Function to implement Dijkstra's algorithm
void dijkstra(Graph* graph, int src) {
    graph->distances[src] = 0;
    insertIntoPriorityQueue(graph, 0, src);
    
    while (graph->priorityQueue != NULL) {
        PriorityQueue* currentElement = extractMinFromPriorityQueue(graph);
        int currentNode = currentElement->node;
        int currentDistance = currentElement->distance;
        
        if (graph->visited[currentNode]) {
            free(currentElement);
            continue;
        }
        
        graph->visited[currentNode] = 1;
        
        Edge* temp = graph->adjLists[currentNode];
        while (temp != NULL) {
            int neighbor = temp->dest;
            int weight = temp->weight;
            
            if (!graph->visited[neighbor] && graph->distances[neighbor] > graph->distances[currentNode] + weight) {
                graph->distances[neighbor] = graph->distances[currentNode] + weight;
                insertIntoPriorityQueue(graph, graph->distances[neighbor], neighbor);
            }
            
            temp = temp->next;
        }
        
        free(currentElement);
    }
}

// Example usage
int main() {
    int numNodes = 5;
    Graph* graph = createGraph(numNodes);
    
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 2, 1, 2);
    addEdge(graph, 2, 3, 5);
    addEdge(graph, 3, 4, 3);
    
    dijkstra(graph, 0);
    
    for (int i = 0; i < numNodes; i++) {
        printf("Shortest distance from node 0 to node %d: %d\n", i, graph->distances[i]);
    }
    
    return 0;
}
