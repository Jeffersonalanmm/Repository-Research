#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure for a tree node
typedef struct Node {
    int data;
    int color; // 0 for red, 1 for black
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        // Handle memory allocation error
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
void rightRotate(Node** root, Node* x) {
    Node* y = x->left;
    x->left = y->right;
    if (y->right != NULL) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

// Function to insert a new node into the tree
void insertNode(Node** root, int data) {
    Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        (*root)->color = 1; // Root node is black
        return;
    }
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
    if (newNode->parent == NULL) {
        newNode->color = 1; // Root node is black
        return;
    }
    if (newNode->parent->parent == NULL) {
        return;
    }
    fixInsert(root, newNode);
}

// Function to fix the tree after insertion
void fixInsert(Node** root, Node* k) {
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

// Function to generate 1000 random inputs
void generateRandomInputs(Node** root) {
    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        int data = rand() % 1000;
        insertNode(root, data);
    }
}

int main() {
    Node* root = NULL;
    generateRandomInputs(&root);
    return 0;
}
