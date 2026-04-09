#include <stdio.h>
#include <stdlib.h>


int binarySearch(int arr[], int left, int right, int x) {
  while (left <= right) {
    int mid = left + (right - left) / 2;


    if (arr[mid] == x)
      return mid;


    if (arr[mid] < x)
      left = mid + 1;


    else
      right = mid - 1;
  }


  return -1;
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

    // Função de comparação para o qsort
    int compare_ints(const void* a, const void* b) {
        return (*(int*)a - *(int*)b);
    }

    // Ordena o array antes da busca binária
    qsort(array, size, sizeof(int), compare_ints);

    int target = 42;  // Valor a ser buscado

    // Corrigido: nome da função e parâmetros
    int index = binarySearch(array, 0, size - 1, target);

    free(array);
    return 0;
}
