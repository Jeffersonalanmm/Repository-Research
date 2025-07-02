#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a pile in the patience sort algorithm
typedef struct Pile {
    int* values;
    int size;
    int capacity;
} Pile;

// Function to create a new pile
Pile* createPile(int capacity) {
    Pile* pile = (Pile*) malloc(sizeof(Pile));
    pile->values = (int*) malloc(sizeof(int) * capacity);
    pile->size = 0;
    pile->capacity = capacity;
    return pile;
}

// Function to add a value to a pile
void addToPile(Pile* pile, int value) {
    if (pile->size == pile->capacity) {
        pile->capacity *= 2;
        pile->values = (int*) realloc(pile->values, sizeof(int) * pile->capacity);
    }
    pile->values[pile->size++] = value;
}

// Function to merge two piles
Pile* mergePiles(Pile* pile1, Pile* pile2) {
    Pile* mergedPile = createPile(pile1->capacity + pile2->capacity);
    int i = 0, j = 0;
    while (i < pile1->size && j < pile2->size) {
        if (pile1->values[i] <= pile2->values[j]) {
            addToPile(mergedPile, pile1->values[i++]);
        } else {
            addToPile(mergedPile, pile2->values[j++]);
        }
    }
    while (i < pile1->size) {
        addToPile(mergedPile, pile1->values[i++]);
    }
    while (j < pile2->size) {
        addToPile(mergedPile, pile2->values[j++]);
    }
    free(pile1->values);
    free(pile1);
    free(pile2->values);
    free(pile2);
    return mergedPile;
}

// Function to perform patience sort
Pile* patienceSort(int* arr, int size) {
    Pile** piles = (Pile**) malloc(sizeof(Pile*) * size);
    int pileCount = 0;
    for (int i = 0; i < size; i++) {
        Pile* newPile = createPile(1);
        addToPile(newPile, arr[i]);
        int j = 0;
        while (j < pileCount && piles[j]->values[piles[j]->size - 1] < newPile->values[0]) {
            j++;
        }
        if (j < pileCount) {
            piles[j] = mergePiles(piles[j], newPile);
        } else {
            piles[pileCount++] = newPile;
        }
    }
    Pile* result = piles[0];
    for (int i = 1; i < pileCount; i++) {
        result = mergePiles(result, piles[i]);
    }
    free(piles);
    return result;
}

// Function to generate random input
int* generateRandomInput(int size) {
    int* arr = (int*) malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }
    return arr;
}

int main() {
    FILE *file = fopen("../../inputs.txt", "r");
    if (!file) {
        return 1;
    }

    int arr[1000];
    int size = 0;
    while (size < 1000 && fscanf(file, "%d", &arr[size]) == 1) {
        size++;
    }
    fclose(file);

    if (size == 0) {
        return 1;
    }

    Pile* sortedPile = patienceSort(arr, size);

    free(sortedPile->values);
    free(sortedPile);

    return 0;
}
