#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

typedef struct {
    int *array;
    int front;
    int rear;
    int capacity;
    int size;
} Queue;

Queue* createQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->array = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = INITIAL_CAPACITY;
    queue->size = 0;
    return queue;
}

void enqueue(Queue *queue, int value) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->array = (int*)realloc(queue->array, queue->capacity * sizeof(int));
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = value;
    queue->size++;
}

int dequeue(Queue *queue) {
    if (queue->size == 0) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    int value = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return value;
}

int isEmpty(Queue *queue) {
    return queue->size == 0;
}

void freeQueue(Queue *queue) {
    free(queue->array);
    free(queue);
}

int main() {
    Queue *queue = createQueue();

    // 1000 random inputs
    for (int i = 0; i < 1000; i++) {
        enqueue(queue, rand() % 1000); // Random values between 0 and 999
    }

    while (!isEmpty(queue)) {
        dequeue(queue);
    }

    freeQueue(queue);
    return 0;
}
