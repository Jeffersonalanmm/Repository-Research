#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

int main() {
    int *array = (int*)malloc(MAX * sizeof(int));
    int max = 0, i;

    srand(time(NULL));

    // Generate 1000 random numbers
    for (i = 0; i < MAX; i++) {
        array[i] = rand() % 1000;
        if (array[i] > max) {
            max = array[i];
        }
    }

    // Create beads
    int *beads = (int*)calloc(max + 1, sizeof(int));
    for (i = 0; i < MAX; i++) {
        beads[array[i]]++;
    }

    // Accumulate beads
    for (i = 1; i <= max; i++) {
        beads[i] += beads[i - 1];
    }

    // Build the output array
    int *output = (int*)malloc(MAX * sizeof(int));
    for (i = 0; i < MAX; i++) {
        output[--beads[array[i]]] = array[i];
    }

    // Free memory
    free(array);
    free(beads);
    free(output);

    return 0;
}