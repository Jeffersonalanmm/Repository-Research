#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure for a Red-Black Tree node
typedef struct Node {
    int data;
    int color; // 0 for red, 1 for black
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->color = 0; // New node is red
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

// Function to perform left rotation
void leftRotate(Node** root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

// Function to perform right rotation
void rightRotate(Node** root, Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != NULL) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == NULL) {
        *root = x;
    } else if (y == y->parent->right) {
        y->parent->right = x;
    } else {
        y->parent->left = x;
    }
    x->right = y;
    y->parent = x;
}

// Function to fix the tree after insertion
void fixInsertion(Node** root, Node* k) {
    Node* u;
    while (k->parent != NULL && k->parent->color == 0) {
        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left;
            if (u->color == 0) {
                u->color = 1;
                k->parent->color = 1;
                k->parent->parent->color = 0;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    rightRotate(root, k);
                }
                k->parent->color = 1;
                k->parent->parent->color = 0;
                leftRotate(root, k->parent->parent);
            }
        } else {
            u = k->parent->parent->right;

            if (u->color == 0) {
                u->color = 1;
                k->parent->color = 1;
                k->parent->parent->color = 0;
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    k = k->parent;
                    leftRotate(root, k);
                }
                k->parent->color = 1;
                k->parent->parent->color = 0;
                rightRotate(root, k->parent->parent);
            }
        }
        if (k == *root) {
            break;
        }
    }
    (*root)->color = 1;
}

// Function to insert a new node into the Red-Black Tree
void insertNode(Node** root, int data) {
    Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
    } else {
        Node* y = NULL;
        Node* x = *root;
        while (x != NULL) {
            y = x;
            if (newNode->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        newNode->parent = y;
        if (newNode->data < y->data) {
            y->left = newNode;
        } else {
            y->right = newNode;
        }
    }
    if (newNode->parent == NULL) {
        newNode->color = 1;
        return;
    }
    if (newNode->parent->parent == NULL) {
        return;
    }
    fixInsertion(root, newNode);
}

// Function to test the Red-Black Tree implementation
int main() {
    srand(time(NULL));
    Node* root = NULL;
    for (int i = 0; i < 1000; i++) {
        int data = rand() % 10000;
        insertNode(&root, data);
    }
    return 0;
}
