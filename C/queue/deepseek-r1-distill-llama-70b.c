#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
    int size;
} Queue;

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, int value) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        return -1; // Indicate error (empty queue)
    }
    int value = q->front->data;
    QueueNode* temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->size--;
    if (q->size == 0) {
        q->rear = NULL;
    }
    return value;
}

int queueSize(Queue* q) {
    return q->size;
}

// Example usage with 1000 random inputs
#include <time.h>
#include <stdlib.h>

void testQueue() {
    Queue q;
    initQueue(&q);
    srand(time(NULL));
    
    for (int i = 0; i < 1000; i++) {
        int num = rand() % 1000;
        enqueue(&q, num);
    }
    
    while (!isEmpty(&q)) {
        printf("Dequeued: %d\n", dequeue(&q));
    }
}