#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

int main() {
    srand(time(NULL));
    int n = 1000;
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
    selection_sort(arr, n);
    free(arr);
    return 0;
}
