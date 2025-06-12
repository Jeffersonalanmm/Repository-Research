#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int arr[1000];
  srand(time(NULL));

  for (int i = 0; i < 1000; i++) {
    arr[i] = rand() % 1000;
  }

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