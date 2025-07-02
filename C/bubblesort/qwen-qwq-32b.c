#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int i, j, swapped;
    for (i = 0; i < n-1; i++) {
        swapped = 0;
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}

int main() {
    FILE* f = fopen("../../inputs.txt", "r");
    if (f == NULL) {
        return 1;
    }

    int capacity = 1000;
    int* array = (int*)malloc(capacity * sizeof(int));
    if (array == NULL) {
        fclose(f);
        return 1;
    }

    int size = 0;
    while (fscanf(f, "%d", &array[size]) == 1) {
        size++;
        if (size >= capacity) {
            capacity *= 2;
            int* temp = realloc(array, capacity * sizeof(int));
            if (temp == NULL) {
                free(array);
                fclose(f);
                return 1;
            }
            array = temp;
        }
    }
    fclose(f);
    bubbleSort(array, size);
    free(array);
    return 0;
}