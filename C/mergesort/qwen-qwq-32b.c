#include <stdio.h>
#include <stdlib.h>

#define INSERTION_SORT_THRESHOLD 15

void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void merge(int arr[], int left, int mid, int right, int temp[]) {
    // Copy elements to temp
    for (int i = left; i <= right; i++) {
        temp[i] = arr[i];
    }

    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (temp[i] <= temp[j]) {
            arr[k] = temp[i];
            i++;
        } else {
            arr[k] = temp[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        arr[k] = temp[i];
        i++;
        k++;
    }

    while (j <= right) {
        arr[k] = temp[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right, int temp[]) {
    if (right - left + 1 < INSERTION_SORT_THRESHOLD) {
        insertionSort(arr, left, right);
        return;
    }
    if (left < right) {
        int mid = left + (right - left)/2;
        mergeSort(arr, left, mid, temp);
        mergeSort(arr, mid+1, right, temp);
        merge(arr, left, mid, right, temp);
    }
}

void mergeSortWrapper(int arr[], int n) {
    if (n <= 1) return;
    int *temp = (int*)malloc(n * sizeof(int));
    if (temp == NULL) {
        // handle error
        return;
    }
    mergeSort(arr, 0, n-1, temp);
    free(temp);
}

int main() {
    int arr[1000];
    int n = 0;

    FILE *file = fopen("../../inputs.txt", "r");
    if (!file) {
        return 1;
    }

    while (fscanf(file, "%d", &arr[n]) == 1 && n < 1000) {
        n++;
    }
    fclose(file);

    mergeSortWrapper(arr, n);

    return 0;
}
