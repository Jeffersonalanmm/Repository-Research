#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check if array is sorted
int is_sorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to shuffle the array
void shuffle(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to implement Bogo Sort
void bogo_sort(int arr[], int n) {
    while (!is_sorted(arr, n)) {
        shuffle(arr, n);
    }
}

int main() {
    srand(time(NULL)); // seed for random number generation

    int n = 1000; // number of elements
    int* arr = (int*)malloc(n * sizeof(int));

    // generate random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    bogo_sort(arr, n);

    // store the sorted array in a file
    FILE* fp = fopen("sorted_array.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);

    free(arr);
    return 0;
}