#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int *array = (int*)malloc(MAX * sizeof(int));
    int max = 0, i;

    FILE* f = fopen("../../inputs.txt", "r");
    if (!f) {
        return 1;
    }

    // Leitura dos valores do arquivo e descoberta do valor máximo
    for (i = 0; i < MAX; i++) {
        if (fscanf(f, "%d", &array[i]) != 1) {
            fclose(f);
            free(array);
            return 1;
        }
        if (array[i] > max) max = array[i];
    }

    fclose(f);

    // Criação do vetor de contagem (beads)
    int *beads = (int*)calloc(max + 1, sizeof(int));
    for (i = 0; i < MAX; i++) {
        beads[array[i]]++;
    }

    for (i = 1; i <= max; i++) {
        beads[i] += beads[i - 1];
    }

    // Construção do array ordenado
    int *output = (int*)malloc(MAX * sizeof(int));
    for (i = 0; i < MAX; i++) {
        output[--beads[array[i]]] = array[i];
    }

    // Liberação de memória
    free(array);
    free(beads);
    free(output);

    return 0;
}