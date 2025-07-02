#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Beadsort
void beadsort(int* array, int size) {
    if (size <= 1) return;

    int max = *array;
    for (int i = 1; i < size; i++) {
        if (array[i] > max) max = array[i];
    }

    int pegs = max + 1;
    int positions = max + 2;

    // Create a 2D array to represent pegs and positions
    int** bead_pillar = (int**)malloc(pegs * sizeof(int*));
    for (int i = 0; i < pegs; i++) {
        bead_pillar[i] = (int*)malloc(positions * sizeof(int));
        for (int j = 0; j < positions; j++) {
            bead_pillar[i][j] = 0;
        }
    }

    // Drop the beads
    for (int i = 0; i < size; i++) {
        int current = array[i];
        for (int j = 0; j < pegs; j++) {
            if (bead_pillar[j][current] == 0) {
                bead_pillar[j][current] = 1;
                break;
            }
        }
    }

    // Collect the sorted beads
    int index = 0;
    for (int j = positions - 1; j >= 0; j--) {
        for (int i = 0; i < pegs; i++) {
            if (bead_pillar[i][j] == 1) {
                array[index++] = j;
            }
        }
    }

    // Free the memory
    for (int i = 0; i < pegs; i++) {
        free(bead_pillar[i]);
    }
    free(bead_pillar);
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