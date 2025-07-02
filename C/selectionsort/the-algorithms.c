/**
 * @file
 * @brief [Selection sort](https://en.wikipedia.org/wiki/Selection_sort)
 * algorithm implementation.
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Swapped two numbers using pointer
 * @param first first pointer of first number
 * @param second second pointer of second number
 */
void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

/**
 * Selection sort algorithm implements
 * @param arr array to be sorted
 * @param size size of array
 */
void selectionSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(arr + i, arr + min_index);
        }
    }
}

/** Test function
  * @returns None
  */
static void test()
{
    const int size = rand() % 500; /* random array size */
    int *arr = (int *)calloc(size, sizeof(int));

    /* generate size random numbers from -50 to 49 */
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 100) - 50; /* signed random numbers */
    }
    selectionSort(arr, size);
    for (int i = 0; i < size - 1; ++i)
    {
        assert(arr[i] <= arr[i + 1]);
    }
    free(arr);
}

/** Driver Code */
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

    selectionSort(arr, size);

    free(arr);
    return 0;
}
