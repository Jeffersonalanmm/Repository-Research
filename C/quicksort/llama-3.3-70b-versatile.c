#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// Function to generate an array of 1000 random integers
void generateRandomArray(int arr[]) {
    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        arr[i] = rand() % 1001;
    }
}

// Function to test the Quick Sort implementation
void testQuickSort() {
    int arr[1000];
    generateRandomArray(arr);
    quickSort(arr, 0, 999);
}

int main() {
    testQuickSort();
    return 0;
}
