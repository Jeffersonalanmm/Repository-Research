#include <stdio.h>

int binary_search(int array[], int size, int target) {
    if (size <= 0) {
        return -1; // Invalid size
    }
    
    int low = 0;
    int high = size - 1;
    
    while (low <= high) {
        // Calculate mid to avoid overflow
        int mid = low + (high - low) / 2;
        
        if (array[mid] == target) {
            return mid;
        } else if (array[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return -1; // Target not found
}
