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
    srand(time(NULL));
    int array[1000];
    for (int i = 0; i < 1000; i++) {
        array[i] = rand() % 10000;
    }
    int writes = cycle_sort(array, 1000);
}