////////////////////////////////////////////////////////////////////////////////
// INCLUDES
#include "include.h"
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// GLOBAL VARIABLES
int count;

////////////////////////////////////////////////////////////////////////////////
// MAIN ENTRY POINT
void create()
{
    head = NULL;
    tail = NULL;
}

/**
 * Puts an item into the Queue.
 */
void enque(int x)
{
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = x;
        head->pre = NULL;
        tail = head;
    }
    else
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = x;
        tmp->next = tail;
        tail = tmp;
    }
}

/**
 * Takes the next item from the Queue.
 */
int deque()
{
    int returnData = 0;
    if (head == NULL)
    {
        printf("ERROR: Deque from empty queue.\n");
        exit(1);
    }
    else
    {
        returnData = head->data;
        if (head->pre == NULL)
            head = NULL;
        else
            head = head->pre;
        head->next = NULL;
    }
    return returnData;
}

/**
 * Returns the size of the Queue.
 */
int size() { return count; }

int main(int argc, char const *argv[])
{
    create();

    FILE *f = fopen("../../inputs.txt", "r");
    if (!f) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int x;
    while (fscanf(f, "%d", &x) == 1) {
        enque(x);
    }

    fclose(f);

    // Imprime a fila usando o que você tem, só para ver os dados
    struct node *current = head;


    return 0;
}


