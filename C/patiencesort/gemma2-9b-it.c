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
    int n = 0;

    FILE *file = fopen("../../inputs.txt", "r");
    if (!file) {
        return 1;
    }

    while (n < MAX_SIZE && fscanf(file, "%d", &arr[n]) == 1) {
        n++;
    }
    fclose(file);

    patience_sort(arr, n);

    // Opcional: imprimir o array ordenado para verificar
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
