#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at index
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to build a max heap
void build_max_heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

// Function to perform heap sort
void heap_sort(int arr[], int n) {
    build_max_heap(arr, n);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to test heap sort
void test_heap_sort(int* arr, int n) {
    heap_sort(arr, n);
}

int main() {
    int n = 1000;
    int* arr = (int*)malloc(n * sizeof(int));

    // Generate random inputs
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000;

    test_heap_sort(arr, n);

    // Free allocated memory
    free(arr);

    return 0;
}