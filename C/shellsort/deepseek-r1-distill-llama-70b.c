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
    FILE *file = fopen("../../inputs.txt", "r");
    if (!file) {
        return 1;
    }
    int arr[1000];
    int n = 0;

    while (fscanf(file, "%d", &arr[n]) == 1 && n < 1000) {
        n++;
    }

    shell_sort(arr, n);
    fclose(file);

    return 0;
}