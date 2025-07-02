#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a pile in Patience Sort
typedef struct Pile {
    int* elements;
    int size;
    int capacity;
} Pile;

// Function to create a new pile
Pile* createPile(int capacity) {
    Pile* pile = (Pile*)malloc(sizeof(Pile));
    pile->elements = (int*)malloc(sizeof(int) * capacity);
    pile->size = 0;
    pile->capacity = capacity;
    return pile;
}

// Function to insert an element into a pile
void insert(Pile* pile, int element) {
    if (pile->size == pile->capacity) {
        pile->capacity *= 2;
        pile->elements = (int*)realloc(pile->elements, sizeof(int) * pile->capacity);
    }
    pile->elements[pile->size++] = element;
}

// Function to perform binary search to find the correct pile for an element
int binarySearch(Pile** piles, int numPiles, int target) {
    int left = 0, right = numPiles - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (piles[mid]->elements[piles[mid]->size - 1] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

// Function to perform Patience Sort
int* patienceSort(int* arr, int n) {
    int numPiles = 0;
    int maxPiles = 10;
    Pile** piles = (Pile**)malloc(sizeof(Pile*) * maxPiles);

    for (int i = 0; i < n; i++) {
        int element = arr[i];

        // Find the correct pile for the element using binary search
        int pileIndex = binarySearch(piles, numPiles, element);

        // If the element is larger than all existing piles, create a new pile
        if (pileIndex == numPiles) {
            if (numPiles == maxPiles) {
                maxPiles *= 2;
                piles = (Pile**)realloc(piles, sizeof(Pile*) * maxPiles);
            }
            piles[numPiles] = createPile(10);
            insert(piles[numPiles], element);
            numPiles++;
        } else {
            // Insert the element into the correct pile
            insert(piles[pileIndex], element);
        }
    }

    // Merge the piles to get the sorted array
    int* sortedArr = (int*)malloc(sizeof(int) * n);
    int index = 0;
    while (numPiles > 0) {
        int minIndex = 0;
        int minValue = piles[0]->elements[0];
        for (int i = 1; i < numPiles; i++) {
            if (piles[i]->elements[0] < minValue) {
                minIndex = i;
                minValue = piles[i]->elements[0];
            }
        }
        sortedArr[index++] = minValue;
        piles[minIndex]->elements[0] = piles[minIndex]->elements[--piles[minIndex]->size];
        if (piles[minIndex]->size == 0) {
            free(piles[minIndex]->elements);
            free(piles[minIndex]);
            for (int i = minIndex; i < numPiles - 1; i++) {
                piles[i] = piles[i + 1];
            }
            numPiles--;
        }
    }

    // Free the memory allocated for piles
    free(piles);

    return sortedArr;
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

    int* sorted = patienceSort(arr, n);  // Corrigido nome da função e uso do retorno

    // Imprimir para verificar
    for (int i = 0; i < n; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    free(sorted);  // Libera o array alocado dinamicamente

    return 0;
}
