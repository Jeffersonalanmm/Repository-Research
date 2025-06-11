#include <stdio.h>

// Function to perform cycle sort
void cycleSort(int arr[], int n) {
    int writes = 0;

    for (int cycleStart = 0; cycleStart < n - 1; cycleStart++) {
        int item = arr[cycleStart];
        int pos = cycleStart;

        for (int i = cycleStart + 1; i < n; i++) {
            if (arr[i] < item) {
                pos++;
            }
        }

        if (pos == cycleStart) {
            continue;
        }

        while (item == arr[pos]) {
            pos++;
        }

        // Swap item with the found position
        int temp = arr[pos];
        arr[pos] = item;
        item = temp;

        writes++;

        // Move the item to its correct position
        while (pos != cycleStart) {
            pos = cycleStart;

            for (int i = cycleStart + 1; i < n; i++) {
                if (arr[i] < item) {
                    pos++;
                }
            }

            while (item == arr[pos]) {
                pos++;
            }

            // Swap item with the found position
            temp = arr[pos];
            arr[pos] = item;
            item = temp;

            writes++;
        }
    }

    return;
}

// Function to check if the array is sorted
int isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

// Driver code
int main() {
    int arr[] = {4, 3, 2, 10, 12, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cycleSort(arr, n);

    // Check if the array is sorted
    if (isSorted(arr, n)) {
        printf("Array is sorted\n");
    } else {
        printf("Array is not sorted\n");
    }

    return 0;
}