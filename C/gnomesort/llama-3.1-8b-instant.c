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
    int arr[1000];
    int size = 0;

    FILE *file = fopen("../../inputs.txt", "r");
    if (!file) {
        return 1;
    }

    while (fscanf(file, "%d", &arr[size]) == 1 && size < 1000) {
        size++;
    }
    fclose(file);

    gnomeSort(arr, size);
    return 0;
}