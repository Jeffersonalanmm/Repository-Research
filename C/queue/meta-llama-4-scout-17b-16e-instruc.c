#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(Queue* q) {
    return (q->front == NULL);
}

void enqueue(Queue* q, int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        return -1; // or handle error
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = temp->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return data;
}

void freeQueue(Queue* q) {
    while (q->front != NULL) {
        Node* temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    free(q);
}

int main() {
    srand(time(NULL));
    Queue* q = createQueue();

    for (int i = 0; i < 1000; i++) {
        int data = rand() % 1000;
        enqueue(q, data);
    }

    int arr[1000];
    int index = 0;

    while (!isEmpty(q)) {
        arr[index++] = dequeue(q);
    }

    freeQueue(q);

    // assertions or further processing can be done here
    return 0;
}