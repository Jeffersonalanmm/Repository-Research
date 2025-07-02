
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
} Node;

typedef struct Pile {
    Node* top;
} Pile;

void patienceSort(int* arr, int n) {
    if (n <= 1) return;

    Pile* piles = (Pile*)malloc(n * sizeof(Pile));
    int* tops = (int*)malloc(n * sizeof(int));
    int piles_count = 0;

    for (int i = 0; i < n; i++) {
        int x = arr[i];
        int low = 0, high = piles_count - 1;
        int pos = piles_count;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (tops[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
                pos = mid;
            }
        }

        if (pos == piles_count) {
            // Create new pile
            piles[piles_count].top = (Node*)malloc(sizeof(Node));
            piles[piles_count].top->data = x;
            piles[piles_count].top->prev = NULL;
            tops[piles_count++] = x;
        } else {
            // Add to existing pile
            Node* new_node = (Node*)malloc(sizeof(Node));
            new_node->data = x;
            new_node->prev = piles[pos].top;
            piles[pos].top = new_node;
            tops[pos] = x;
        }
    }

    // Reconstruct sorted array
    int* sorted = (int*)malloc(n * sizeof(int);
    int index = 0;

    for (int i = piles_count - 1; i >= 0; i--) {
        Node* current = piles[i].top;
        while (current != NULL) {
            sorted[index++] = current->data;
            current = current->prev;
        }
    }

    // Reverse to get sorted order
    for (int i = 0; i < n; i++) {
        arr[i] = sorted[n - 1 - i];
    }

    free(sorted);
    free(tops);
    for (int i = 0; i < piles_count; i++) {
        Node* current = piles[i].top;
        while (current != NULL) {
            Node* temp = current;
            current = current->prev;
            free(temp);
        }
    }
    free(piles);
}

