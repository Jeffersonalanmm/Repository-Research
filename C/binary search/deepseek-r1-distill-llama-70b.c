#include <stdio.h>
#include <stdlib.h> //add by author
int binary_search(int array[], int size, int target) {
    if (size <= 0) {
        return -1; // Invalid size
    }
    
    int low = 0;
    int high = size - 1;
    
    while (low <= high) {
        // Calculate mid to avoid overflow
        int mid = low + (high - low) / 2;
        
        if (array[mid] == target) {
            return mid;
        } else if (array[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return -1; // Target not found
}

// Função de comparação para qsort
int compare_ints(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
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
    qsort(array, size, sizeof(int), compare_ints);

    int target = 42;  // Valor a ser buscado
    int index = binary_search(array, size, target);

    free(array);
    return 0;
}