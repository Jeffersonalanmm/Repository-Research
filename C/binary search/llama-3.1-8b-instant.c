#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search
int binary_search(int* arr, int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If target is greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1;
        }

        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }

    // If we reach here, then the element was not present
    return -1;
}

// Function to create a sorted array
int* create_sorted_array(int n) {
    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    return arr;
}

int main() {
    int n = 1000;
    int* arr = create_sorted_array(n);

    // Test the binary search function
    for (int i = 0; i < n; i++) {
        int result = binary_search(arr, n, i);
        // If the result is not -1, then the element was found
        if (result != -1) {
            // Do nothing
        } else {
            // If the result is -1, then the element was not found
        }
    }

    free(arr);
    return 0;
}