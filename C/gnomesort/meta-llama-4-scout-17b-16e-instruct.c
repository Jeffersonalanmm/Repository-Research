#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gnome_sort(int arr[], int n) {
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
    return 0;
}

int main() {
    srand(time(NULL));
    int arr[1000];
    for (int i = 0; i < 1000; i++) {
        arr[i] = rand() % 1000;
    }
    gnome_sort(arr, 1000);
}

