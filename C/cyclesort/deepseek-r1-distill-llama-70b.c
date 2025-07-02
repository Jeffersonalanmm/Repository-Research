#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cycleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == i + 1) continue; // Element already in correct position
        int j = i;
        int k = i;
        do {
            k = arr[j] - 1;
            arr[j] = arr[k];
            j = k;
        } while (k != i);
        arr[j] = i + 1;
    }
}

int main() {
    FILE* f = fopen("../../inputs.txt", "r");
    if (f == NULL) {
        return 1;
    }

    int capacity = 1000;
    int* array = malloc(capacity * sizeof(int));
    if (!array) {
        fclose(f);
        return 1;
    }

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

    cycleSort(array, size);
    free(array);
    return 0;
}