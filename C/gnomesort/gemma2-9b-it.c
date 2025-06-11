#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gnomeSort(int arr[], int n) {
    int i = 1;
    while (i < n) {
        if (arr[i] >= arr[i - 1]) {
            i++;
        } else {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            i--;
        }
    }
}

int main() {
    srand(time(NULL));
    int n = 1000;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    gnomeSort(arr, n);

    return 0;
}