#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr[1000];
    FILE *file = fopen("../../inputs.txt", "r");

    if (!file) {
      
        return 1;
    }

    for (int i = 0; i < 1000; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);

  for (int i = 0; i < 999; i++) {
    int minIndex = i;
    for (int j = i + 1; j < 1000; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    int temp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = temp;
  }

  return 0;
}