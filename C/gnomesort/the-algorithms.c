#include <stdio.h>
#include <stdlib.h>

void sort(int *numbers, int size)
{
    int pos = 0;
    while (pos < size)
    {
        if (numbers[pos] >= numbers[pos - 1])
            pos++;
        else
        {
            int tmp = numbers[pos - 1];
            numbers[pos - 1] = numbers[pos];
            numbers[pos] = tmp;
            pos--;

            if (pos == 0)
                pos = 1;
        }
    }
}

void display(int *array, int n)
{
    int i;
    for (i = 0; i < n; ++i) printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    FILE *file = fopen("../../inputs.txt", "r");
    if (!file)
    {
        return 1;
    }

    int *numbers = malloc(1000 * sizeof(int));  // buffer fixo para até 1000 números
    if (!numbers)
    {
        fclose(file);
        return 1;
    }

    int size = 0;
    while (fscanf(file, "%d", &numbers[size]) == 1)
    {
        size++;
        if (size >= 1000) break;  // para evitar ultrapassar o buffer
    }

    fclose(file);

    int *numbers2 = malloc((size + 1) * sizeof(int));
    if (!numbers2)
    {
        free(numbers);
        return 1;
    }

    numbers2[0] = -2147483648;  // sentinela
    for (int i = 0; i < size; i++)
    {
        numbers2[i + 1] = numbers[i];
    }

    sort(numbers2 + 1, size);


    free(numbers2);
    free(numbers);

    return 0;
}
