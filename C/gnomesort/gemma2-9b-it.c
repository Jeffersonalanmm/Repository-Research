#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gnomeSort(int arr[], int n) {
    int i = 1;
    while (i < n) {
        if (arr[i] >= arr[i - 1]) {
            i++;
        } else {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            i--;
        }
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

    gnomeSort(arr, size);

    return 0;
}