
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gnome_sort(int arr[], int n) {
    int i = 1;
    while (i < n) {
        if (arr[i-1] <= arr[i]) {
            i++;
        } else {
            int temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
            if (i > 1) {
                i--;
            }
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

    gnome_sort(arr, size);

    return 0;
}