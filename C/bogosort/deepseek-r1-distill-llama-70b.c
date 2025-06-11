#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

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
    int array[1000];
    // Initialize array with random values
    for (int i = 0; i < 1000; i++) {
        array[i] = rand() % 10000;  // Random number between 0 and 9999
    }
    bogoSort(array, 1000);
    return 0;
}