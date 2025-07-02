#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} PatienceStack;

PatienceStack* createStack(int capacity) {
    PatienceStack *stack = (PatienceStack*)malloc(sizeof(PatienceStack));
    stack->data = (int*)malloc(capacity * sizeof(int));
    stack->size = 0;
    stack->capacity = capacity;
    return stack;
}

void push(PatienceStack *stack, int value) {
    if (stack->size == stack->capacity) {
        stack->capacity *= 2;
        stack->data = (int*)realloc(stack->data, stack->capacity * sizeof(int));
    }
    stack->data[stack->size++] = value;
}

int pop(PatienceStack *stack) {
    if (stack->size == 0) {
        return -1; // Error: stack is empty
    }
    return stack->data[--stack->size];
}

int top(PatienceStack *stack) {
    if (stack->size == 0) {
        return -1; // Error: stack is empty
    }
    return stack->data[stack->size - 1];
}

void freeStack(PatienceStack *stack) {
    free(stack->data);
    free(stack);
}

void patienceSort(int *arr, int n) {
    PatienceStack **stacks = (PatienceStack**)malloc(n * sizeof(PatienceStack*));
    for (int i = 0; i < n; i++) {
        stacks[i] = createStack(n);
    }

    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < n && stacks[j]->size > 0 && stacks[j]->data[stacks[j]->size - 1] < arr[i]) {
            push(stacks[j + 1], pop(stacks[j]));
            j++;
        }
        push(stacks[j], arr[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        while (stacks[i]->size > 0) {
            arr[k++] = pop(stacks[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        freeStack(stacks[i]);
    }
    free(stacks);
}

int main() {
    FILE *file = fopen("../../inputs.txt", "r");
    if (!file) {
        fprintf(stderr, "Erro ao abrir o arquivo ../../inputs.txt\n");
        return 1;
    }

    int arr[1000];
    int n = 0;

    while (n < 1000 && fscanf(file, "%d", &arr[n]) == 1) {
        n++;
    }
    fclose(file);

    if (n == 0) {
        fprintf(stderr, "Nenhum dado lido do arquivo.\n");
        return 1;
    }

    patienceSort(arr, n);  // Ordena o array arr in-place

    // Imprimir para verificar
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
