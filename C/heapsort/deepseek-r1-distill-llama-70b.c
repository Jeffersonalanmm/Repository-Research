
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void heapify(int array[], int size, int index);
void build_heap(int array[], int size);
void heap_sort(int array[], int size);
void test_heap_sort();

// Implementation
void heapify(int array[], int size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && array[left] > array[largest]) {
        largest = left;
    }

    if (right < size && array[right] > array[largest]) {
        largest = right;
    }

    if (largest != index) {
        int temp = array[index];
        array[index] = array[largest];
        array[largest] = temp;
        heapify(array, size, largest);
    }
}

void build_heap(int array[], int size) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(array, size, i);
    }
}

void heap_sort(int array[], int size) {
    build_heap(array, size);

    for (int i = size - 1; i > 0; --i) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapify(array, i, 0);
    }
}

void test_heap_sort() {
    srand(time(NULL));
    int size = 1000;
    int* array = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 10000;
    }

    heap_sort(array, size);

    for (int i = 0; i < size - 1; ++i) {
        if (array[i] > array[i + 1]) {
            printf("Sorting error detected!\n");
            exit(EXIT_FAILURE);
        }
    }

    free(array);
}

int main() {
    test_heap_sort();
    return 0;
}
