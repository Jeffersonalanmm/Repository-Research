/**
 * @file
 * @brief Implementation of [merge
 * sort](https://en.wikipedia.org/wiki/Merge_sort) algorithm
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @addtogroup sorting Sorting algorithms
 * @{
 */
/** Swap two integer variables
 * @param [in,out] a pointer to first variable
 * @param [in,out] b pointer to second variable
 */
void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

/**
 * @brief Perform merge of segments.
 *
 * @param a array to sort
 * @param l left index for merge
 * @param r right index for merge
 * @param n total number of elements in the array
 */
void merge(int *a, int l, int r, int n)
{
    int *b = (int *)malloc(n * sizeof(int)); /* dynamic memory must be freed */
    if (b == NULL)
    {
        exit(EXIT_FAILURE);
    }
    int c = l;
    int p1, p2;
    p1 = l;
    p2 = ((l + r) / 2) + 1;
    while ((p1 < ((l + r) / 2) + 1) && (p2 < r + 1))
    {
        if (a[p1] <= a[p2])
        {
            b[c++] = a[p1];
            p1++;
        }
        else
        {
            b[c++] = a[p2];
            p2++;
        }
    }

    if (p2 == r + 1)
    {
        while ((p1 < ((l + r) / 2) + 1))
        {
            b[c++] = a[p1];
            p1++;
        }
    }
    else
    {
        while ((p2 < r + 1))
        {
            b[c++] = a[p2];
            p2++;
        }
    }

    for (c = l; c < r + 1; c++) a[c] = b[c];

    free(b);
}

/** Merge sort algorithm implementation
 * @param a array to sort
 * @param n number of elements in the array
 * @param l index to sort from
 * @param r index to sort till
 */
void merge_sort(int *a, int n, int l, int r)
{
    if (r - l == 1)
    {
        if (a[l] > a[r])
            swap(&a[l], &a[r]);
    }
    else if (l != r)
    {
        merge_sort(a, n, l, (l + r) / 2);
        merge_sort(a, n, ((l + r) / 2) + 1, r);
        merge(a, l, r, n);
    }

    /* no change if l == r */
}
/** @} */

/** Main function */
#include <stdio.h>
#include <stdlib.h>

// Declare a função de sort que você tem (merge_sort, heapsort, etc.)
void merge_sort(int *a, int n, int l, int r);

int main()
{
    FILE *file = fopen("../../inputs.txt", "r");
    if (!file)
    {
        return 1;
    }

    int count = 0, temp;

    // Contar quantos números tem no arquivo
    while (fscanf(file, "%d", &temp) == 1)
    {
        count++;
    }

    if (count == 0)
    {
        fclose(file);
        return 1;
    }

    // Alocar array dinâmico do tamanho exato
    int *numbers = malloc(count * sizeof(int));
    if (!numbers)
    {
        fclose(file);
        return 1;
    }

    rewind(file); // Voltar para o começo do arquivo

    // Ler os números no array
    for (int i = 0; i < count; i++)
    {
        if (fscanf(file, "%d", &numbers[i]) != 1)
        {
            free(numbers);
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    // Aqui você chama sua função de ordenação, ex:
    merge_sort(numbers, count, 0, count - 1);

    free(numbers);

    return 0;
}
