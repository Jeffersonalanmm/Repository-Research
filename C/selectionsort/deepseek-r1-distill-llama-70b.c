#include <stdio.h>

void selection_sort(int array[], int size) {
    int i, j, min_idx, temp;
    int is_sorted = 0;

    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        is_sorted = 1;

        // Find the minimum element in the unsorted portion
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
                is_sorted = 0;
            }
        }

        // Swap the found minimum element with the first element of the unsorted portion
        if (!is_sorted) {
            temp = array[i];
            array[i] = array[min_idx];
            array[min_idx] = temp;
        }

        // If no swaps occurred, the array is already sorted
        if (is_sorted)
            break;
    }
}

// Example usage
int main() {
    FILE *file = fopen("../../inputs.txt", "r");
    if (!file) {
        return 1;
    }
    int arr[1000];
    int n = 0;

    while (fscanf(file, "%d", &arr[n]) == 1 && n < 1000) {
        n++;
    }

    selection_sort(arr, n);
    fclose(file);

    return 0;
}