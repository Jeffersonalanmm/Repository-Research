#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int value;
    int* pile;
    int size;
    int capacity;
} patience_sort_t;

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* generate_random_array(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    return arr;
}

int patience_sort(int* arr, int n) {
    int** piles = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        piles[i] = (int*)malloc(n * sizeof(int));
        piles[i][0] = 0;
    }

    int pile_count = 1;
    piles[0][0] = arr[0];

    for (int i = 1; i < n; i++) {
        int low = 0, high = pile_count - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[i] > piles[mid][0]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (low == pile_count) {
            piles[low] = (int*)realloc(piles[low], (n + 1) * sizeof(int));
            piles[low][0] = arr[i];
            piles[low][1] = 0;
            pile_count++;
        } else {
            int j = 1;
            while (piles[low][j] != 0) {
                j++;
            }
            piles[low][j] = arr[i];
        }
    }

    int* sorted_arr = (int*)malloc(n * sizeof(int));
    int index = 0;
    for (int i = 0; i < pile_count; i++) {
        int j = 1;
        while (piles[i][j] != 0) {
            sorted_arr[index++] = piles[i][j];
            j++;
        }
    }

    for (int i = 0; i < n; i++) {
        free(piles[i]);
    }
    free(piles);

    for (int i = 0; i < n; i++) {
        arr[i] = sorted_arr[i];
    }
    free(sorted_arr);

    return 0;
}

int main() {
    srand(time(NULL));
    int n = 1000;
    int* arr = generate_random_array(n);
    patience_sort(arr, n);
    qsort(arr, n, sizeof(int), compare);
    // Verification code can be added here
    free(arr);
    return 0;
}
