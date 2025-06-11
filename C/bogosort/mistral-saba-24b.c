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
    srand(time(0));
    int n = 1000;
    int *array = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        array[i] = rand() % 10000;
    }

    bogoSort(array, n);

    free(array);
    return 0;
}