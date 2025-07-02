#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VERTICES 1000
#define EDGES 4000

int main() {
    FILE *file = fopen("graph_input.txt", "w");
    if (!file) {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    srand(42); // Semente fixa para resultados reprodutíveis

    for (int i = 0; i < EDGES; i++) {
        int source = rand() % VERTICES;
        int destination = rand() % VERTICES;
        int weight = (rand() % 1000) - 500; // Peso entre -500 e 499

        fprintf(file, "%d %d %d\n", source, destination, weight);
    }

    fclose(file);
    return 0;
}
