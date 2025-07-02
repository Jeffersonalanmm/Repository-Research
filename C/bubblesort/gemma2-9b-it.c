#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  FILE* f = fopen("../../inputs.txt", "r");
  if (f == NULL) {
      return 1;
  }

  int arr[1000];
  for (int i = 0; i < 1000; i++) {
      if (fscanf(f, "%d", &arr[i]) != 1) {
          break;  // Para caso o arquivo tenha menos de 1000 valores
      }
  }
  fclose(f);

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
