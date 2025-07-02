#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&arr[i], &arr[min_idx]);
        }
    }
}

// Function to test the selection sort implementation
void testSelectionSort(int* arr, int n) {
    selectionSort(arr, n);
}

int main() {
    FILE *file = fopen("../../inputs.txt", "r");
    if (!file) {
        return 1;
    }
    int arr[1000];
    int n = 0;

    while (fscanf(file, "%d", &arr[n]) == 1 && n < 1000) {
        n++;
    }

    selectionSort(arr, n);
    fclose(file);
    return 0;
}