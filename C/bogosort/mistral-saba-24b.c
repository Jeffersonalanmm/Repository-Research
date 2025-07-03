#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *array, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int isSorted(int *array, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (array[i] > array[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void bogoSort(int *array, int n) {
    while (!isSorted(array, n)) {
        shuffle(array, n);
    }
}

int main() {
    FILE* f = fopen("../../inputs_bogosort.txt", "r");
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

    // Lê os números do arquivo
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

    // Ordena com bogoSort (atenção: é muito lento para arrays grandes)
    bogoSort(array, size);


    free(array);
    return 0;
}