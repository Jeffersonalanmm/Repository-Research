#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool check_sorted(int *a, int n)
{
    while (--n >= 1)
    {
        if (a[n] < a[n - 1])
            return false;
    }
    return true;
}

void shuffle(int *a, int n)
{
    int i, t, r;
    for (i = 0; i < n; i++)
    {
        t = a[i];
        r = rand() % n;
        a[i] = a[r];
        a[r] = t;
    }
}

void sort(int *a, int n)
{
    while (!check_sorted(a, n)) shuffle(a, n);
}

int main()
{
    int numbers[1000];
    FILE *file = fopen("../../inputs.txt", "r");
    if (!file)
    {
                return 1;
    }

    for (int i = 0; i < 1000; i++)
    {
        if (fscanf(file, "%d", &numbers[i]) != 1)
        {
            fclose(file);
            return 1;
        }
    }
    fclose(file);

    sort(numbers, 1000);
    return 0;
}