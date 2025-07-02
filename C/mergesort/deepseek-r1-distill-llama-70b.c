#include <stdio.h>
#include <stdlib.h>

// Function to perform insertion sort on smaller arrays
void insertionSort(int *array, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= left && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

// Function to merge two sorted subarrays
void merge(int *array, int *aux, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (array[i] <= array[j]) {
            aux[k++] = array[i++];
        } else {
            aux[k++] = array[j++];
        }
    }

    // Copy remaining elements from left subarray
    while (i <= mid) {
        aux[k++] = array[i++];
    }

    // Copy remaining elements from right subarray
    while (j <= right) {
        aux[k++] = array[j++];
    }

    // Copy sorted elements back to original array
    for (int m = left; m <= right; m++) {
        array[m] = aux[m];
    }
}

// Optimized merge sort function
void mergeSort(int *array, int *aux, int left, int right) {
    // Use insertion sort for small subarrays
    if (right - left + 1 < 10) {
        insertionSort(array, left, right);
        return;
    }

    int mid = (left + right) / 2;
    mergeSort(array, aux, left, mid);
    mergeSort(array, aux, mid + 1, right);
    merge(array, aux, left, mid, right);
}

// Driver function to initialize auxiliary array and call merge sort
void sortArray(int *array, int size) {
    int *aux = (int *)malloc(size * sizeof(int));
    mergeSort(array, aux, 0, size - 1);
    free(aux);
}

// Example usage
int main() {
    int arr[1000];
    int size = 0;

    FILE *file = fopen("../../inputs.txt", "r");
    if (!file) {
        return 1;
    }

    while (fscanf(file, "%d", &arr[size]) == 1 && size < 1000) {
        size++;
    }
    fclose(file);

    sortArray(arr, size);

    return 0;
}