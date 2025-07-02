#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(sizeof(int) * capacity);
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->size == 0;
}

int isFull(Queue* queue) {
    return queue->size == queue->capacity;
}

void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        // Handle queue full error
        return;
    }
    queue->data[queue->rear] = value;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        // Handle queue empty error
        return -1; // or some other sentinel value
    }
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return value;
}

void testQueue() {
    Queue* queue = createQueue(1000);
    for (int i = 0; i < 1000; i++) {
        enqueue(queue, rand() % 1000);
    }
    for (int i = 0; i < 1000; i++) {
        dequeue(queue);
    }
    free(queue->data);
    free(queue);
}

int main() {
    FILE *file = fopen("../../inputs.txt", "r");
    if (!file) {
        return 1;
    }

    Queue *q = createQueue(1000); 
    if (!q) {
        fclose(file);
        return 1;
    }

    int num, count = 0;
    while (count < 1000 && fscanf(file, "%d", &num) == 1) {
        enqueue(q, num);
        count++;
    }
    fclose(file);

    free(q); 
    return 0;
}

