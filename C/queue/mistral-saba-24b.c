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
    FILE *file = fopen("../../inputs.txt", "r");
    if (!file) {
        return 1;
    }

    Queue *q = createQueue(); 
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
