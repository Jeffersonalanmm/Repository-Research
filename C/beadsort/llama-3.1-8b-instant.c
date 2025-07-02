#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //add by author
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

// Function to sort beads using Beadsort algorithm
void beadSort(int* values, int n) {
    // Create a linked list for each unique value
    int* uniqueValues = (int*) malloc(n * sizeof(int));
    int uniqueCount = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (values[i] == uniqueValues[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            uniqueValues[uniqueCount++] = values[i];
        }
    }

    // Create a linked list for each unique value
    Bead** linkedLists = (Bead**) malloc(uniqueCount * sizeof(Bead*));
    for (int i = 0; i < uniqueCount; i++) {
        linkedLists[i] = NULL;
    }

    // Insert each value into its corresponding linked list
    for (int i = 0; i < n; i++) {
        int index = -1;
        for (int j = 0; j < uniqueCount; j++) {
            if (values[i] == uniqueValues[j]) {
                index = j;
                break;
            }
        }
        if (index != -1) {
            Bead* bead = createBead(values[i]);
            bead->next = linkedLists[index];
            linkedLists[index] = bead;
        }
    }

    // Merge the linked lists in ascending order
    for (int i = 0; i < uniqueCount - 1; i++) {
        Bead* current = linkedLists[i];
        Bead* next = linkedLists[i + 1];
        while (current != NULL && next != NULL) {
            if (current->value <= next->value) {
                Bead* temp = next;
                next = next->next;
                current->next = temp;
                temp->next = NULL;
            } else {
                Bead* temp = current;
                current = current->next;
                temp->next = next;
                next->next = NULL;
            }
        }
        linkedLists[i + 1] = current == NULL ? next : current;
    }

    // Copy the sorted values back into the original array
    int* sortedValues = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < uniqueCount; i++) {
        Bead* current = linkedLists[i];
        while (current != NULL) {
            sortedValues[i++] = current->value;
            current = current->next;
        }
    }

    // Free the memory
    free(uniqueValues);
    free(linkedLists);
    free(sortedValues);
}

int main() {
    srand(time(NULL));

    FILE* f = fopen("../../inputs.txt", "r");

    int capacity = 1000;
    int* array = (int*)malloc(capacity * sizeof(int));
    int size = 0;

    while (fscanf(f, "%d", &array[size]) == 1) {
        size++;
        if (size >= capacity) {
            capacity *= 2;
            array = (int*)realloc(array, capacity * sizeof(int));
        }
    }

    fclose(f);

    beadSort(array, size);


    free(array);
    return 0;
}
