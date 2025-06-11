```c
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
    srand(time(0));
    int n = 1000;
    int *arr = (int *)malloc(n * sizeof(int));

    // Generate random inputs
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Random values between 0 and 999
    }

    beadsort(arr, n);

    free(arr);
    return 0;
}
```