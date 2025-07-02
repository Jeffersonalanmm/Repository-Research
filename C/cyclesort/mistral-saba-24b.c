#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cycleSort(int *arr, int n) {
    int writes = 0;

    for (int cycleStart = 0; cycleStart <= n - 1; cycleStart++) {
        int item = arr[cycleStart];

        int pos = cycleStart;
        for (int i = cycleStart + 1; i <= n - 1; i++) {
            if (arr[i] < item) {
                pos++;
            }
        }

        if (pos == cycleStart) {
            continue;
        }

        while (item == arr[pos]) {
            pos += 1;
        }

        if (pos != cycleStart) {
            int temp = item;
            item = arr[pos];
            arr[pos] = temp;
            writes++;
        }

        while (pos != cycleStart) {
            pos = cycleStart;
            for (int i = cycleStart + 1; i <= n - 1; i++) {
                if (arr[i] < item) {
                    pos += 1;
                }
            }

            while (item == arr[pos]) {
                pos += 1;
            }

            if (item != arr[pos]) {
                int temp = item;
                item = arr[pos];
                arr[pos] = temp;
                writes++;
            }
        }
    }
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

    cycleSort(array, size);
    free(array);
    return 0;
}