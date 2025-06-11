#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cycleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == i + 1) continue; // Element already in correct position
        int j = i;
        int k = i;
        do {
            k = arr[j] - 1;
            arr[j] = arr[k];
            j = k;
        } while (k != i);
        arr[j] = i + 1;
    }
}

int main() {
    srand(time(NULL));
    int n = 1000;
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        int r = rand() % n;
        int temp = arr[i];
        arr[i] = arr[r];
        arr[r] = temp;
    }
    cycleSort(arr, n);
    free(arr);
    return 0;
}