#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000

int main() {
  int arr[ARRAY_SIZE];
  srand(time(NULL));

  // Generate random input
  for (int i = 0; i < ARRAY_SIZE; i++) {
    arr[i] = rand() % 1000;
  }

  // Bogo Sort implementation
  int swapped;
  do {
    swapped = 0;
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
      for (int j = i + 1; j < ARRAY_SIZE; j++) {
        if (arr[i] > arr[j]) {
          int temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
          swapped = 1;
        }
      }
    }
  } while (swapped);

  return 0;
}
