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
    srand(time(NULL)); // Seed for random number generation

    int n = 1000; // Number of elements in the array
    int* arr = generateRandomSortedArray(n);

    // Perform Binary Search on the generated array
    int target = arr[rand() % n]; // Choose a random target from the array
    int result = binarySearch(arr, target, 0, n - 1);

    // To avoid using printf, we can verify the result by checking if it's within bounds
    if (result >= 0 && result < n) {
        // Do nothing, just verify
    }

    free(arr); // Deallocate the dynamically allocated memory
    return 0;
}
