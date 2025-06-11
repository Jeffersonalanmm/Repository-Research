#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_V 1000

typedef struct {
    int vertex;
    int distance;
} Element;

typedef struct {
    Element *heap[MAX_V];
    int size;
} MinHeap;

void swap(Element *x, Element *y) {
    Element temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(MinHeap *heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->heap[left]->distance < heap->heap[smallest]->distance)
        smallest = left;

    if (right < heap->size && heap->heap[right]->distance < heap->heap[smallest]->distance)
        smallest = right;

    if (smallest != idx) {
        swap(&heap->heap[idx], &heap->heap[smallest]);
        minHeapify(heap, smallest);
    }
}

void buildMinHeap(MinHeap *heap) {
    int n = heap->size;
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(heap, i);
}

Element extractMin(MinHeap *heap) {
    if (heap->size <= 0)
        return (Element){-1, INT_MAX};

    if (heap->size == 1) {
        heap->size--;
        return *heap->heap[0];
    }

    Element root = *heap->heap[0];
    heap->heap[0] = heap->heap[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);

    return root;
}

void insertMinHeap(MinHeap *heap, Element key) {
    heap->size++;
    int i = heap->size - 1;
    heap->heap[i] = (Element*)malloc(sizeof(Element));
    *heap->heap[i] = key;

    while (i != 0 && heap->heap[(i - 1) / 2]->distance > heap->heap[i]->distance) {
        swap(heap->heap[i], heap->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void dijkstra(int graph[MAX_V][MAX_V], int src, int V) {
    int dist[MAX_V];
    MinHeap heap;
    heap.size = 0;

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        Element *element = (Element*)malloc(sizeof(Element));
        element->vertex = i;
        element->distance = INT_MAX;
        insertMinHeap(&heap, *element);
    }

    dist[src] = 0;
    heap.heap[0]->distance = 0;
    buildMinHeap(&heap);

    while (heap.size > 0) {
        Element u = extractMin(&heap);
        int uVertex = u.vertex;

        for (int v = 0; v < V; v++) {
            if (graph[uVertex][v] && dist[uVertex] != INT_MAX &&
                dist[uVertex] + graph[uVertex][v] < dist[v]) {
                dist[v] = dist[uVertex] + graph[uVertex][v];
                for (int i = 0; i < heap.size; i++) {
                    if (heap.heap[i]->vertex == v) {
                        heap.heap[i]->distance = dist[v];
                        break;
                    }
                }
                buildMinHeap(&heap);
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int V = 1000;
    int graph[MAX_V][MAX_V];

    // Initialize the graph with random values
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = (rand() % 100); // Random values between 0 and 99
        }
    }

    int src = 0; // Source vertex
    dijkstra(graph, src, V);

    return 0;
}
