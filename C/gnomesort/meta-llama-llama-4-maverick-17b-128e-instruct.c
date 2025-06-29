
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gnome_sort(int arr[], int n) {
    int i = 1;
    while (i < n) {
        if (arr[i-1] <= arr[i]) {
            i++;
        } else {
            int temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
            if (i > 1) {
                i--;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int n = 1000;
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    gnome_sort(arr, n);
    return 0;
}
