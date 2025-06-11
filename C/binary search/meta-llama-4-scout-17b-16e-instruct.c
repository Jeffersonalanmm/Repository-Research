#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(int arr[], int target, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // not found
}

int main() {
    srand(time(NULL));
    int arr[1000];
    for (int i = 0; i < 1000; i++) {
        arr[i] = rand() % 10000;
    }
    int target = arr[rand() % 1000];

    // sort the array
    for (int i = 0; i < 1000; i++) {
        for (int j = i + 1; j < 1000; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int result = binary_search(arr, target, 0, 999);
}