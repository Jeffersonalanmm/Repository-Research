#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

int isFull(Queue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return value;
}

int main() {
    srand(time(NULL));
    Queue* q = createQueue();

    for (int i = 0; i < 1000; i++) {
        int value = rand() % 100;
        enqueue(q, value);
    }

    for (int i = 0; i < 1000; i++) {
        dequeue(q);
    }

    return 0;
}
