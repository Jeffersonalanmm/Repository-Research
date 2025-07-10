#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int size = 1000;

    FILE *file = fopen("inputs.txt", "w");
    if (!file) {
        perror("Error to open file");        
        return 1;
    }
    
    srand(42); // Semente fixa para garantir sempre a mesma sequência

    for (int i = 0; i < size; i++) {
        int num = rand() % 10000000;
        fprintf(file, "%d\n", num);   
    }

    fclose(file);

    return 0;
}