#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Bubblesort
void bubblesort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Flag to track if any swaps were made in the current iteration
        int swapped = 0;
        
        // Iterate through the unsorted portion of the array
        for (int j = 0; j < n - i - 1; j++) {
            // If the current element is greater than the next element, swap them
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                swapped = 1;
            }
        }
        
        // If no swaps were made in the current iteration, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

// Example usage with 1000 inputs
int main() {
    int array[1000];
    for (int i = 0; i < 1000; i++) { //adicionar no prompt que os valores precisam ser aleatórios
        array[i] = i;
    }
    
    // Reverse the array to make it unsorted
    for (int i = 0; i < 500; i++) {
        swap(&array[i], &array[999 - i]);
    }
    
    bubblesort(array, 1000);
    // No print statements as per the requirement
    return 0;
}