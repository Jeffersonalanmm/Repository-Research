#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check if an array is sorted
int is_sorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to shuffle an array
void shuffle(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to implement Bogo Sort
void bogo_sort(int arr[], int n) {
    while (!is_sorted(arr, n)) {
        shuffle(arr, n);
    }
}

// Function to generate a random array
void generate_random_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

int main() {
    FILE* f = fopen("../../inputs.txt", "r");
    if (f == NULL) {
        return 1;
    }

    int capacity = 1000;
    int* array = (int*)malloc(capacity * sizeof(int));
    if (array == NULL) {
        fclose(f);
        return 1;
    }
    int size = 0;

    // Lê os números do arquivo
    while (fscanf(f, "%d", &array[size]) == 1) {
        size++;
        if (size >= capacity) {
            capacity *= 2;
            int* temp = realloc(array, capacity * sizeof(int));
            if (temp == NULL) {
                free(array);
                fclose(f);
                return 1;
            }
            array = temp;
        }
    }

    fclose(f);

    // Ordena com bogoSort (atenção: é muito lento para arrays grandes)
    bogoSort(array, size);



    free(array);
    return 0;
}