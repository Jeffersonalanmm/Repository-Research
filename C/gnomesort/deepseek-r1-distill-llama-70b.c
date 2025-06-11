#include <stdio.h>

void gnome_sort_optimized(int arr[], int size) {
    int swapped;
    do {
        swapped = 0;
        for (int i = 1; i < size; ) {
            if (arr[i] > arr[i-1]) {
                ++i;
            } else {
                // Swap elements
                int temp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = temp;
                swapped = 1;
                if (i > 1) {
                    --i;
                } else {
                    i = 1;
                }
            }
        }
    } while (swapped);
}

// Example usage with 1000 random inputs (demonstrated with a smaller set for brevity)
int main() {
    int arr[] = {5, 3, 2, 4, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    gnome_sort_optimized(arr, size);
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}