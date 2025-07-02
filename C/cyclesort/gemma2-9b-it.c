#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 2

int cycle_sort(int arr[], int n) {
    int cycles = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == i) {
            continue;
        }
        int pos = arr[i];
        while (arr[pos] != pos) {
            int temp = arr[pos];
            arr[pos] = arr[arr[pos]];
            arr[arr[pos]] = temp;
            cycles++;
        }
        arr[pos] = pos;
    }
    return cycles;
}

int main() {
    int arr[ARRAY_SIZE];
    srand(time(NULL));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % ARRAY_SIZE;
    }

    int cycles = cycle_sort(arr, ARRAY_SIZE);


    return 0;
}