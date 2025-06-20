#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int arr[1000];
  srand(time(NULL));

  for (int i = 0; i < 1000; i++) {
    arr[i] = rand() % 1000;
  }

  int n = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  return 0;
}
