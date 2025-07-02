#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform cycle sort
void cycleSort(int arr[], int n) {
    int writes = 0;
    for (int cycleStart = 0; cycleStart <= n - 2; cycleStart++) {
        int item = arr[cycleStart];
        int pos = cycleStart;
        for (int i = cycleStart + 1; i < n; i++)
            if (arr[i] < item)
                pos++;
        if (pos == cycleStart)
            continue;
        while (item == arr[pos])
            pos += 1;
        int temp = arr[pos];
        arr[pos] = item;
        item = temp;
        writes++;
        while (pos != cycleStart) {
            pos = cycleStart;
            for (int i = cycleStart + 1; i < n; i++)
                if (arr[i] < item)
                    pos += 1;
            while (item == arr[pos])
                pos += 1;
            temp = arr[pos];
            arr[pos] = item;
            item = temp;
            writes++;
        }
    }
}

// Function to generate random array
int* generateRandomArray(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000;
    return arr;
}

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