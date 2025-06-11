#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Bubble Sort
void bubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // Flag to track if any swaps were made in the current iteration
        int swapped = 0;
        
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                swapped = 1;
            }
        }
        
        // If no swaps were made in the current iteration, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

// Function to generate an array of 1000 random integers
int* generateRandomArray(int size) {
    int* array = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000;
    }
    return array;
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    int size = 1000;
    int* array = generateRandomArray(size);
    bubbleSort(array, size);
    free(array);
    return 0;
}