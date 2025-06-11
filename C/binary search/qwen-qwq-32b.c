#include <stdlib.h>

#include <time.h>

int compare(const void *a, const void *b) {

{

    int val1 = *(int*)a;

    int val2 = *(int*)b;

    if (val1 < val2) return -1;

    else if (val1 > val2) return 1;

    else return 0;

}

int binary_search(int arr[], int n, int target) {

{

    int low = 0;

    int high = n -1;

    while (low <= high) {

        int mid = low + (high - low)/2;

        if (arr[mid] == target) return mid;

        else if (target < arr[mid]) {

            high = mid -1;

        } else {

            low = mid +1;

    }

    return -1;

}

int main() {

    int arr[1000];

    srand(time(0));

    for (int i=0; i<1000; i++) {

        arr[i] = rand() % 10000; // random numbers between 0 and 9999.

    }

    qsort(arr, 1000, sizeof(int), compare);

    // Now test each element in the array.

    for (int i=0; i<1000; i++) {

        int target = arr[i];

        int index = binary_search(arr, 1000, target);

        if (index == -1 || arr[index] != target) {

            exit(EXIT_FAILURE);

        }

    }

    // Also, maybe test some non-present targets?

    // But the user might just need 1000 tests. The above loop does 1000 tests.

    return 0;

}