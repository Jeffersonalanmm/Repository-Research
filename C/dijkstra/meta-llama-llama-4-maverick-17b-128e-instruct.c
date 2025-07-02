#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 1000

// Structure to represent a node in the heap
typedef struct MinHeapNode {
    int v;
    int dist;
} MinHeapNode;

// Structure to represent a min heap
typedef struct MinHeap {
    int size;
    int capacity;
    int* pos;
    MinHeapNode** array;
} MinHeap;

// Function to create a new min heap node
MinHeapNode* newMinHeapNode(int v, int dist) {
    MinHeapNode* minHeapNode = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}

// Function to create a min heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->pos = (int*)malloc(sizeof(int) * capacity);
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(sizeof(MinHeapNode*) * capacity);
    return minHeap;
}

// Function to swap two min heap nodes
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Function to heapify the min heap
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        MinHeapNode* smallestNode = minHeap->array[smallest];
        MinHeapNode* idxNode = minHeap->array[idx];

        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

// Function to check if the min heap is empty
int isEmpty(MinHeap* minHeap) {
    return minHeap->size == 0;
}

// Function to extract the minimum node from the min heap
MinHeapNode* extractMin(MinHeap* minHeap) {
    if (isEmpty(minHeap))
        return NULL;

    MinHeapNode* root = minHeap->array[0];

    MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

// Function to decrease the key in the min heap
void decreaseKey(MinHeap* minHeap, int v, int dist) {
    int i = minHeap->pos[v];

    minHeap->array[i]->dist = dist;

    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}

// Function to check if a vertex is in the min heap
int isInMinHeap(MinHeap* minHeap, int v) {
    if (minHeap->pos[v] < minHeap->size)
        return 1;
    return 0;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int** graph, int src) {
    int* dist = (int*)malloc(sizeof(int) * V);
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    MinHeap* minHeap = createMinHeap(V);

    for (int i = 0; i < V; i++) {
        MinHeapNode* node = newMinHeapNode(i, dist[i]);
        minHeap->array[i] = node;
        minHeap->pos[i] = i;
        minHeap->size++;
    }

    while (!isEmpty(minHeap)) {
        MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && isInMinHeap(minHeap, v) && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                decreaseKey(minHeap, v, dist[v]);
            }
        }
    }

    // Use the calculated distances as needed, for example, store them in a file or pass them to another function
   // FILE* file = fopen("distances.txt", "w");
    //for (int i = 0; i < V; i++) {
    //    fprintf(file, "%d ", dist[i]);
  //  }
    //fclose(file);

    free(dist);
    free(minHeap->pos);
    free(minHeap->array);
    free(minHeap);
}

int main() {
    FILE *file = fopen("../../graph_input.txt", "r");
    if (!file) {
        return 1;
    }

    int** graph = (int**)malloc(sizeof(int*) * V);
    for (int i = 0; i < V; i++) {
        graph[i] = (int*)malloc(sizeof(int) * V);
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    int src, dest, weight;
    while (fscanf(file, "%d %d %d", &src, &dest, &weight) == 3) {
        if (src >= 0 && src < V && dest >= 0 && dest < V && weight >= 0) {
            graph[src][dest] = weight;
        }
    }

    fclose(file);

    dijkstra(graph, 0);

    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
