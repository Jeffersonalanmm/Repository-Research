#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 1000

int main() {
  int arr[MAX_VALUE];
  srand(time(NULL));

  // Generate 1000 random numbers
  for (int i = 0; i < MAX_VALUE; i++) {
    arr[i] = rand() % MAX_VALUE;
  }

  // Beadsort implementation
  int n = MAX_VALUE;
  int beads[MAX_VALUE] = {0};

  for (int i = 0; i < n; i++) {
    beads[arr[i]]++;
  }

  int index = 0;
  for (int i = 0; i < MAX_VALUE; i++) {
    for (int j = 0; j < beads[i]; j++) {
      arr[index++] = i;
    }
  }

  return 0;
}
