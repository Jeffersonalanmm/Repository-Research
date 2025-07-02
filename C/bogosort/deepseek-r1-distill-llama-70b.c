#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>//add by author

#define MAX_ATTEMPTS 1000000  // Maximum number of sorting attempts

// Function to check if the array is sorted in ascending order
bool isSorted(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

// Fisher-Yates shuffle algorithm to randomly permute the array
void shuffle(int* array, int size) {
    for (int i = size - 1; i > 0; i--) {
        // Generate a random index between 0 and i (inclusive)
        int j = rand() % (i + 1);
        // Swap elements at indices i and j
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Optimized Bogo Sort implementation
void bogoSort(int* array, int size) {
    srand(time(NULL));  // Seed the random number generator
    int attempts = 0;
    
    while (!isSorted(array, size) && attempts < MAX_ATTEMPTS) {
        shuffle(array, size);
        attempts++;
    }
}

// Example usage in main function
int main() {
    FILE* f = fopen("../../inputs.txt", "r");

    int capacity = 1000;
    int* array = (int*)malloc(capacity * sizeof(int));
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