#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform binary search
int binarySearch(int array[], int target, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == target) {
            return mid;
        } else if (array[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Return -1 if target is not found
}

// Function to generate a sorted array with 1000 random elements
int* generateSortedArray(int* size) {
    *size = 1000;
    int* array = (int*) malloc(*size * sizeof(int));
    for (int i = 0; i < *size; i++) {
        array[i] = i;
    }
    return array;
}

// Function to test the binary search algorithm
void testBinarySearch() {
    int size;
    int* array = generateSortedArray(&size);
    int target = 500; // Target value to search for
    int result = binarySearch(array, target, 0, size - 1);
    free(array);
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    testBinarySearch();
    return 0;
}