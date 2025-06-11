#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Structure to represent a bead
typedef struct Bead {
    int value;
    struct Bead* next;
} Bead;


// Function to create a new bead
Bead* createBead(int value) {
    Bead* bead = (Bead*) malloc(sizeof(Bead));
    bead->value = value;
    bead->next = NULL;
    return bead;
}


// Function to insert a bead into a rod
void insertBead(Bead** rod, int value) {
    Bead* newBead = createBead(value);
    if (*rod == NULL || (*rod)->value > value) {
        newBead->next = *rod;
        *rod = newBead;
    } else {
        Bead* current = *rod;
        while (current->next != NULL && current->next->value < value) {
            current = current->next;
        }
        newBead->next = current->next;
        current->next = newBead;
    }
}


// Function to remove a bead from a rod
int removeBead(Bead** rod) {
    if (*rod == NULL) {
        return -1;
    }
    int value = (*rod)->value;
    Bead* temp = *rod;
    *rod = (*rod)->next;
    free(temp);
    return value;
}


// Function to implement the Beadsort algorithm
void beadSort(int* array, int size) {
    Bead** rods = (Bead**) malloc(size * sizeof(Bead*));
    for (int i = 0; i < size; i++) {
        rods[i] = NULL;
    }


    // Drop the beads
    for (int i = 0; i < size; i++) {
        insertBead(&rods[array[i]], array[i]);
    }


    // Collect the beads
    int index = 0;
    for (int i = 0; i < size; i++) {
        while (rods[i] != NULL) {
            array[index++] = removeBead(&rods[i]);
        }
    }


    free(rods);
}


// Function to generate random numbers
void generateRandomNumbers(int* array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000;
    }
}


int main() {
    int size = 1000;
    int* array = (int*) malloc(size * sizeof(int));
    generateRandomNumbers(array, size);
    beadSort(array, size);
    free(array);
    return 0;
}
