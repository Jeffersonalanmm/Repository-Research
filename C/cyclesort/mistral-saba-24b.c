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
    srand(time(0));
    int n = 1000;
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    cycleSort(arr, n);

    free(arr);
    return 0;
}