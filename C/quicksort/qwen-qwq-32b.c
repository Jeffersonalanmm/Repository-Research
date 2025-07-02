#include <stdlib.h>
#include <stdio.h> //add by author

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insertion_sort(int arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        if (high - low < 16) {
            insertion_sort(arr, low, high);
            return;
        }
        
        // Median-of-three pivot selection
        int mid = low + (high - low)/2;
        if (arr[low] > arr[mid]) swap(&arr[low], &arr[mid]);
        if (arr[mid] > arr[high]) swap(&arr[mid], &arr[high]);
        if (arr[low] > arr[mid]) swap(&arr[low], &arr[mid]);
        swap(&arr[mid], &arr[high]); // Move median to end
        
        int pivot = arr[high];
        int i = low;
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                swap(&arr[i], &arr[j]);
                i++;
            }
        }
        swap(&arr[i], &arr[high]);
        
        quicksort(arr, low, i-1);
        quicksort(arr, i+1, high);
    }
}
int main() {
    FILE *file = fopen("../../inputs.txt", "r");
    if (!file) {
        return 1;
    }
    int arr[1000];
    int n = 0;

    while (fscanf(file, "%d", &arr[n]) == 1 && n < 1000) {
        n++;
    }

    quicksort(arr, 0, n - 1);
    
    fclose(file);

    return 0;
}