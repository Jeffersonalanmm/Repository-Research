#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shell_sort(int* array, int size) {
    // Ciura's gap sequence
    int gaps[] = {701, 301, 132, 57, 23, 11, 6, 3, 2, 1};
    int gap_index = 0;
    int gap;

    for (gap_index = 0; gap_index < sizeof(gaps)/sizeof(gaps[0]); gap_index++) {
        gap = gaps[gap_index];
        if (gap < 1) break;

        for (int i = gap; i < size; i++) {
            int temp = array[i];
            int j = i;

            while (j >= gap && array[j - gap] > temp) {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = temp;
        }
    }
}

int main() {
    srand(time(NULL));
    int size = 1000;
    int* array = (int*) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 10000;
    }

    shell_sort(array, size);

    free(array);
    return 0;
}
