#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    while (1) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest == i)
            break;

        swap(&arr[i], &arr[largest]);
        i = largest;
    }
}

void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n/2 -1; i >=0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements one by one
    for (int i = n-1; i >=0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    const int size = 1000;
    int arr[size];
    srand(time(NULL));

    for (int i =0; i < size; i++) {
        arr[i] = rand() % 10000;
    }

    heapSort(arr, size);

    return 0;
}
