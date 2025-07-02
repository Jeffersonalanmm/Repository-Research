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

    gnome_sort_optimized(arr, size);

    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}