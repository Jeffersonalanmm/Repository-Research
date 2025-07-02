#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *array;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = -1;
    q->rear = -1;
    q->array = (int*)malloc(capacity * sizeof(int));
    return q;
}

void enqueue(Queue *q, int item) {
    if ((q->rear + 1) % q->capacity == q->front) {
        return; // Queue full
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = item;
    if (q->front == -1) {
        q->front = q->rear;
    }
}

int dequeue(Queue *q) {
    if (q->front == -1) {
        return -1; // Queue empty
    }
    int item = q->array[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->capacity;
    }
    return item;
}

void freeQueue(Queue *q) {
    free(q->array);
    free(q);
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
