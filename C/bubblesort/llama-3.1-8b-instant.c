#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Flag to check if any swaps were made in the current iteration
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        // If no swaps were made in the current iteration, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

// Function to test the Bubble Sort implementation
void testBubbleSort() {
    int n = 1000;
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    bubbleSort(arr, n);
    free(arr);
}

int main() {
    testBubbleSort();
    return 0;
}
