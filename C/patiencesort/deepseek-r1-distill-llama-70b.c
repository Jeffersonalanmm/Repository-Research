
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a pile
typedef struct {
    int* elements;
    int size;
} Pile;

// Structure to represent a heap element
typedef struct {
    int value;
    int pile_index;
    int element_index;
} HeapElement;

// Function to create a new pile
Pile* create_pile(int element) {
    Pile* pile = malloc(sizeof(Pile));
    pile->elements = malloc(sizeof(int));
    pile->elements[0] = element;
    pile->size = 1;
    return pile;
}

// Function to add an element to a pile
void add_to_pile(Pile* pile, int element) {
    pile->size++;
    pile->elements = realloc(pile->elements, pile->size * sizeof(int));
    pile->elements[pile->size - 1] = element;
}

// Function to insert an element into the heap
void insert_heap(HeapElement** heap, int* heap_size, int* heap_capacity, HeapElement element) {
    if (*heap_size >= *heap_capacity) {
        *heap_capacity = (*heap_capacity == 0) ? 1 : (*heap_capacity * 2);
        *heap = realloc(*heap, *heap_capacity * sizeof(HeapElement));
    }
    
    (*heap)[*heap_size] = element;
    (*heap_size)++;
    
    int current = *heap_size - 1;
    while (current > 0 && (*heap)[current].value < (*heap)[(current - 1) / 2].value) {
        HeapElement temp = (*heap)[current];
        (*heap)[current] = (*heap)[(current - 1) / 2];
        (*heap)[(current - 1) / 2] = temp;
        current = (current - 1) / 2;
    }
}

// Function to extract the minimum element from the heap
HeapElement extract_min(HeapElement* heap, int* heap_size) {
    HeapElement min = heap[0];
    HeapElement last = heap[*heap_size - 1];
    (*heap_size]--;
    
    if (*heap_size > 0) {
        heap[0] = last;
        int current = 0;
        while (current * 2 + 1 < *heap_size) {
            int left_child = current * 2 + 1;
            int right_child = current * 2 + 2;
            int smallest = current;
            
            if (heap[left_child].value < heap[smallest].value) {
                smallest = left_child;
            }
            if (right_child < *heap_size && heap[right_child].value < heap[smallest].value) {
                smallest = right_child;
            }
            
            if (smallest != current) {
                HeapElement temp = heap[current];
                heap[current] = heap[smallest];
                heap[smallest] = temp;
                current = smallest;
            } else {
                break;
            }
        }
    }
    
    return min;
}

int main() {
    int input_array[] = {3, 6, 2, 1, 4, 5};
    int n = sizeof(input_array) / sizeof(input_array[0]);
    
    // Create an array to hold all piles
    Pile** piles = NULL;
    int num_piles = 0;
    
    for (int i = 0; i < n; i++) {
        int current = input_array[i];
        int added = 0;
        
        // Find the first pile where top > current
        for (int j = 0; j < num_piles; j++) {
            if (piles[j]->elements[piles[j]->size - 1] > current) {
                add_to_pile(piles[j], current);
                added = 1;
                break;
            }
        }
        
        if (!added) {
            // Create a new pile
            piles = realloc(piles, (num_piles + 1) * sizeof(Pile*));
            piles[num_piles] = create_pile(current);
            num_piles++;
        }
    }
    
    // Initialize the heap
    HeapElement* heap = NULL;
    int heap_size = 0;
    int heap_capacity = 0;
    
    for (int i = 0; i < num_piles; i++) {
        if (piles[i]->size > 0) {
            HeapElement element;
            element.value = piles[i]->elements[piles[i]->size - 1];
            element.pile_index = i;
            element.element_index = piles[i]->size - 1;
            insert_heap(&heap, &heap_size, &heap_capacity, element);
        }
    }
    
    // Merge the piles using the heap
    int* result = malloc(n * sizeof(int));
    int result_size = 0;
    
    while (heap_size > 0) {
        HeapElement min_element = extract_min(heap, &heap_size);
        
        result[result_size] = min_element.value;
        result_size++;
        
        // Check if there are more elements in the pile
        Pile* pile = piles[min_element.pile_index];
        if (min_element.element_index > 0) {
            HeapElement new_element;
            new_element.value = pile->elements[min_element.element_index - 1];
            new_element.pile_index = min_element.pile_index;
            new_element.element_index = min_element.element_index - 1;
            insert_heap(&heap, &heap_size, &heap_capacity, new_element);
        }
    }
    
    // Free allocated memory
    for (int i = 0; i < num_piles; i++) {
        free(piles[i]->elements);
        free(piles[i]);
    }
    free(piles);
    free(heap);
    free(result);
    
    return 0;
}
