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
    int array[] = {64, 25, 12, 22, 11};
    int size = sizeof(array) / sizeof(array[0]);
    
    selection_sort(array, size);
    
    return 0;
}
