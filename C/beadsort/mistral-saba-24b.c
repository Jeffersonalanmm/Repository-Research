
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void beadsort(int *arr, int n) {
    int i, j, k, max = 0;
    int *beads = (int *)malloc(n * sizeof(int));

    // Find the maximum value in the array
    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Initialize the beads array
    for (i = 0; i < n; i++) {
        beads[i] = 0;
    }

    // Place beads in the beads array
    for (i = 0; i < n; i++) {
        for (j = 0; j < arr[i]; j++) {
            beads[j] += 1;
        }
    }

    // Sort the array using the beads array
    k = 0;
    for (i = 0; i < max; i++) {
        for (j = 0; j < beads[i]; j++) {
            arr[k++] = i + 1;
        }
    }

    free(beads);
}

int main() {
    srand(time(NULL));

    FILE* f = fopen("../../inputs.txt", "r");

    int capacity = 1000;
    int* array = (int*)malloc(capacity * sizeof(int));
    int size = 0;

    while (fscanf(f, "%d", &array[size]) == 1) {
        size++;
        if (size >= capacity) {
            capacity *= 2;
            array = (int*)realloc(array, capacity * sizeof(int));
        }
    }

    fclose(f);

    beadsort(array, size);


    free(array);
    return 0;
}