#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform insertion sort
void insertion_sort(int array[], int n, int gap) {
    for (int i = gap; i < n; i++) {
        int temp = array[i];
        int j = i;
        while (j >= gap && array[j - gap] > temp) {
            array[j] = array[j - gap];
            j -= gap;
        }
        array[j] = temp;
    }
}

// Function to perform Shell Sort
void shell_sort(int array[], int n) {
    int gap = n / 2;
    while (gap > 0) {
        insertion_sort(array, n, gap);
        gap /= 2;
    }
}

// Function to generate random array
void generate_random_array(int array[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 1000;
    }
}

// Function to check if array is sorted
int is_sorted(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (array[i] > array[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n = 1000;
    int array[n];
    generate_random_array(array, n);
    shell_sort(array, n);
    return 0;
}