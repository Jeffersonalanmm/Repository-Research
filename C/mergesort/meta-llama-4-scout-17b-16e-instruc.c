#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int* arr, int left, int mid, int right) {
    int* left_arr = (int*)malloc((mid - left + 1) * sizeof(int));
    int* right_arr = (int*)malloc((right - mid) * sizeof(int));

    for (int i = 0; i < mid - left + 1; i++) {
        left_arr[i] = arr[left + i];
    }
    for (int i = 0; i < right - mid; i++) {
        right_arr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < mid - left + 1 && j < right - mid) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < mid - left + 1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < right - mid) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }

    free(left_arr);
    free(right_arr);
}

void merge_sort(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    srand(time(NULL));
    int arr[1000];
    for (int i = 0; i < 1000; i++) {
        arr[i] = rand() % 1000;
    }

    merge_sort(arr, 0, 999);

    // No print statements
    return 0;
}
