#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a card
typedef struct Card {
    int value;
    char suit[10];
} Card;

// Structure to represent a pile
typedef struct Pile {
    Card* cards;
    int size;
    int capacity;
} Pile;

// Function to create a new pile
Pile* createPile(int capacity) {
    Pile* pile = (Pile*) malloc(sizeof(Pile));
    pile->cards = (Card*) malloc(sizeof(Card) * capacity);
    pile->size = 0;
    pile->capacity = capacity;
    return pile;
}

// Function to add a card to a pile
void addCard(Pile* pile, Card card) {
    if (pile->size == pile->capacity) {
        pile->capacity *= 2;
        pile->cards = (Card*) realloc(pile->cards, sizeof(Card) * pile->capacity);
    }
    pile->cards[pile->size++] = card;
}

// Function to compare two cards
int compareCards(Card a, Card b) {
    if (a.value < b.value) return -1;
    if (a.value > b.value) return 1;
    return 0;
}

// Function to sort a pile
void sortPile(Pile* pile) {
    qsort(pile->cards, pile->size, sizeof(Card), (int (*)(const void*, const void*)) compareCards);
}

// Function to merge two piles
Pile* mergePiles(Pile* pile1, Pile* pile2) {
    Pile* merged = createPile(pile1->size + pile2->size);
    for (int i = 0; i < pile1->size; i++) {
        addCard(merged, pile1->cards[i]);
    }
    for (int i = 0; i < pile2->size; i++) {
        addCard(merged, pile2->cards[i]);
    }
    sortPile(merged);
    return merged;
}

// Function to implement Patience Sort
Pile* patienceSort(Card* cards, int n) {
    Pile* piles = createPile(n);
    for (int i = 0; i < n; i++) {
        addCard(piles, cards[i]);
    }
    sortPile(piles);
    Pile* sorted = createPile(n);
    for (int i = 0; i < n; i++) {
        Pile* pile = createPile(1);
        addCard(pile, piles->cards[i]);
        sorted = mergePiles(sorted, pile);
    }
    return sorted;
}

// Function to free memory
void freeMemory(Pile* pile) {
    free(pile->cards);
    free(pile);
}

int main() {
    // Create a deck of cards
    Card cards[1000];
    for (int i = 0; i < 1000; i++) {
        cards[i].value = rand() % 13 + 1;
        cards[i].suit[0] = 'S'; // Suit is not used in this implementation
    }

    // Implement Patience Sort
    Pile* sorted = patienceSort(cards, 1000);

    // Free memory
    freeMemory(sorted);

    return 0;
}
