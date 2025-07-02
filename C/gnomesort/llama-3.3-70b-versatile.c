#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Gnome Sort
void gnome_sort(int arr[], int n) {
    int i = 1;
    while (i < n) {
        if (arr[i-1] <= arr[i])
            i++;
        else {
            swap(&arr[i-1], &arr[i]);
            if (i > 1)
                i--;
        }
    }
}

// Function to generate random array
void generate_random_array(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
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

    gnome_sort(arr, size);

    return 0;
}