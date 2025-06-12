#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int patience_sort(int arr[], int size) {
  int i, j, k, temp;
  int *min_heap = (int*)malloc(sizeof(int) * size);
  int heap_size = 0;

  for (i = 0; i < size; i++) {
    // Build min-heap
    j = heap_size;
    while (j > 0) {
      k = (j - 1) / 2;
      if (arr[j] < arr[k]) {
        temp = arr[j];
        arr[j] = arr[k];
        arr[k] = temp;
      }
      j = k;
    }
    heap_size++;
  }

  // Extract sorted elements
  for (i = 0; i < size; i++) {
    // Get minimum element from heap
    temp = arr[0];
    arr[0] = arr[heap_size - 1];
    heap_size--;

    // Heapify
    j = 0;
    while (2 * j + 1 < heap_size) {
      k = 2 * j + 1;
      if (arr[k] < arr[k + 1] && k + 1 < heap_size) {
        k++;
      }
      if (arr[j] > arr[k]) {
        temp = arr[j];
        arr[j] = arr[k];
        arr[k] = temp;
      }
      j = k;
    }
  }

  free(min_heap);
  return 0;
}

int main() {
  int arr[MAX_SIZE];
  srand(time(NULL));

  for (int i = 0; i < MAX_SIZE; i++) {
    arr[i] = rand() % 1000;
  }

  patience_sort(arr, MAX_SIZE);

  return 0;
}