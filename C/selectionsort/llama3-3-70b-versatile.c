#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform selection sort
void selectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&array[i], &array[minIndex]);
        }
    }
}

// Function to generate random array
void generateRandomArray(int array[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000;
    }
}

// Function to check if array is sorted
int isSorted(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int array[1000];
    generateRandomArray(array, 1000);
    selectionSort(array, 1000);
    return isSorted(array, 1000);
}
