#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENT_NR 20000
#define ARRAY_LEN(x) (sizeof(x) / sizeof((x)[0]))
const char *notation =
    "Shell Sort Big O Notation:\
						\n--> Best Case: O(n log(n)) \
						\n--> Average Case: depends on gap sequence \
						\n--> Worst Case: O(n)";

void show_data(int arr[], int len)
{
    int i;

    for (i = 0; i < len; i++) printf("%3d ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void shellSort(int array[], int len)
{
    int i, j, gap;

    for (gap = len / 2; gap > 0; gap = gap / 2)
        for (i = gap; i < len; i++)
            for (j = i - gap; j >= 0 && array[j] > array[j + gap]; j = j - gap)
                swap(&array[j], &array[j + gap]);
}

int main(int argc, const char *argv[])
{
    FILE *inputFile = fopen("../../inputs.txt", "r");
    if (!inputFile) {
        return 1;
    }

    const int size = 1000;
    int *arr = (int *)malloc(size * sizeof(int));
    if (!arr) {
        fclose(inputFile);
        return 1;
    }

    for (int i = 0; i < size; i++) {
        if (fscanf(inputFile, "%d", &arr[i]) != 1) {
            free(arr);
            fclose(inputFile);
            return 1;
        }
    }
    fclose(inputFile);

    shellSort(arr, size);

    free(arr);
    return 0;
}
