#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *array, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Troca array[i] e array[j]
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main() {
    int n = 1000;
    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        perror("Malloc failed");
        return 1;
    }

    // Preenche com 1..n
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    srand(time(NULL)); // Semente baseada no tempo

    shuffle(arr, n);

    FILE *file = fopen("inputs.txt", "w");
    if (!file) {
        perror("Failed to open file");
        free(arr);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
    free(arr);
    return 0;
}
