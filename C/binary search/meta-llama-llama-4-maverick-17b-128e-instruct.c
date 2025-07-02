#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Function to perform Binary Search
int binarySearch(int arr[], int target, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if target is present at the mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore left half
        if (arr[mid] < target)
            low = mid + 1;

        // If target is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If we reach here, then the element was not present
    return -1;
}

// Function to generate a sorted array of 'n' random integers
int* generateRandomSortedArray(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Generate random numbers between 0 and 9999
    }
    // Sort the array in ascending order
    qsort(arr, n, sizeof(int), compare);
    return arr;
}

int main() {
    FILE* f = fopen("../../inputs.txt", "r");
    if (!f) {
        return 1;
    }

    int capacity = 1000;
    int* array = (int*)malloc(capacity * sizeof(int));
    int size = 0;

    while (fscanf(f, "%d", &array[size]) == 1) {
        size++;
        if (size >= capacity) {
            capacity *= 2;
            int* temp = realloc(array, capacity * sizeof(int));
            if (!temp) {
                free(array);
                fclose(f);
                return 1;
            }
            array = temp;
        }
    }
    fclose(f);

    // Ordena o array antes da busca binária
    qsort(array, size, sizeof(int), compare);

    int target = 42;  // Valor a ser buscado
    int index = binarySearch(array, target,0, size-1);

    free(array);
    return 0;
}