#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cycle_sort(int *array, int n) {
    int writes = 0;
    for (int cycleStart = 0; cycleStart < n - 1; cycleStart++) {
        int item = array[cycleStart];
        int pos = cycleStart;
        for (int i = cycleStart + 1; i < n; i++) {
            if (array[i] < item) {
                pos++;
            }
        }
        if (pos == cycleStart) {
            continue;
        }
        while (item == array[pos]) {
            pos++;
        }
        int temp = array[pos];
        array[pos] = item;
        item = temp;
        writes++;
        while (pos != cycleStart) {
            pos = cycleStart;
            for (int i = cycleStart + 1; i < n; i++) {
                if (array[i] < item) {
                    pos++;
                }
            }
            while (item == array[pos]) {
                pos++;
            }
            temp = array[pos];
            array[pos] = item;
            item = temp;
            writes++;
        }
    }
    return writes;
}

int main() {
    FILE* f = fopen("../../inputs.txt", "r");
    if (f == NULL) {
        return 1;
    }

    int capacity = 1000;
    int* array = malloc(capacity * sizeof(int));
    if (!array) {
        fclose(f);
        return 1;
    }

    int size = 0;
    while (fscanf(f, "%d", &array[size]) == 1) {
        size++;
        if (size >= capacity) {
            capacity *= 2;
            int* temp = realloc(array, capacity * sizeof(int));
            if (!temp) {
                free(array);
                fclose(f);
                return 1;
            }
            array = temp;
        }
    }
    fclose(f);

    cycle_sort(array, size);
    free(array);
    return 0;
}