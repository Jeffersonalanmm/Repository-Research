#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for a queue node
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

// Structure for a queue
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
    int size;
} Queue;

// Function to create a new queue node
QueueNode* createQueueNode(int data) {
    QueueNode* newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (!newNode) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    if (!queue) {
        return NULL;
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Function to add an element to the queue
void enqueue(Queue* queue, int data) {
    QueueNode* newNode = createQueueNode(data);
    if (queue->rear) {
        queue->rear->next = newNode;
        queue->rear = newNode;
    } else {
        queue->front = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

// Function to remove an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        return -1; // Queue is empty
    }
    int data = queue->front->data;
    QueueNode* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return data;
}

// Function to get the front element of the queue
int front(Queue* queue) {
    if (isEmpty(queue)) {
        return -1; // Queue is empty
    }
    return queue->front->data;
}

// Function to get the size of the queue
int size(Queue* queue) {
    return queue->size;
}

int main() {
    srand(time(NULL));
    Queue* queue = createQueue();
    for (int i = 0; i < 1000; i++) {
        int data = rand() % 100;
        enqueue(queue, data);
    }
    for (int i = 0; i < 500; i++) {
        dequeue(queue);
    }
    return 0;
}