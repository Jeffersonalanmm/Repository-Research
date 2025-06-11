
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Beadsort
void beadsort(int* arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create a 2D array to represent the beads
    int** beads = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        beads[i] = (int*)malloc((max + 1) * sizeof(int));
        for (int j = 0; j <= max; j++) {
            if (j <= arr[i]) {
                beads[i][j] = 1;
            } else {
                beads[i][j] = 0;
            }
        }
    }

    // Count the beads
    for (int j = 0; j <= max; j++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += beads[i][j];
        }
        // Update the array with the sorted values
        for (int i = n - 1; i >= 0; i--) {
            if (count > 0) {
                beads[i][j] = 1;
                count--;
            } else {
                beads[i][j] = 0;
            }
        }
    }

    // Update the original array with the sorted values
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j <= max; j++) {
            if (beads[i][j] == 1) {
                count++;
            }
        }
        arr[i] = count;
    }

    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        free(beads[i]);
    }
    free(beads);
}

int main() {
    srand(time(NULL));
    int n = 1000;
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    beadsort(arr, n);

    // To verify the correctness, you can uncomment the following lines
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    free(arr);
    return 0;
}