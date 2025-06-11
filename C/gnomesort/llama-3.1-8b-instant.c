#include <stdio.h>

// Function to implement Gnome Sort
void gnomeSort(int arr[], int n) {
    int i = 1;
    while (i < n) {
        if (arr[i - 1] <= arr[i]) {
            i++;
        } else {
            // Swap elements
            int temp = arr[i - 1];
            arr[i - 1] = arr[i];
            arr[i] = temp;
            if (i > 1) {
                i--;
            }
        }
    }
}

// Function to test the Gnome Sort implementation
void testGnomeSort(int arr[], int n) {
    gnomeSort(arr, n);
    // No need to print the result, just return
}

int main() {
    int n = 1000;
    int arr[n];

    // Generate random inputs
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    testGnomeSort(arr, n);

    return 0;
}