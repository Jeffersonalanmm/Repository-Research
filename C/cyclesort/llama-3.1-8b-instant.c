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
    FILE* f = fopen("../../inputs.txt", "r");
    if (f == NULL) {
        return 1;
    }

    int capacity = 1000;
    int* array = malloc(capacity * sizeof(int));
    if (!array) {
        fclose(f);
        return 1;
    }

    int size = 0;
    while (fscanf(f, "%d", &array[size]) == 1) {
        size++;
        if (size >= capacity) {
            capacity *= 2;
            int* temp = realloc(array, capacity * sizeof(int));
            if (!temp) {
                free(array);
                fclose(f);
                return 1;
            }
            array = temp;
        }
    }
    fclose(f);

    cycleSort(array, size);
    free(array);
    return 0;
}