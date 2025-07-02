#include <stdio.h>
#include <stdlib.h>

// Define the AVL tree node structure
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

// Function to calculate the height of a node
int height(Node *node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Function to get the balance factor of a node
int balanceFactor(Node *node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Function to perform a right rotation
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// Function to perform a left rotation
Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

// Function to insert a new node into the AVL tree
Node *insert(Node *node, int data) {
    // 1. Perform the normal BST insertion
    if (node == NULL) {
        node = (Node *)malloc(sizeof(Node));
        node->data = data;
        node->left = node->right = NULL;
        node->height = 1;
        return node;
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node;
    }

    // 2. Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = balanceFactor(node);

    // 4. If this node becomes unbalanced, then there are 4 cases

    // Case 1 - Left Left
    if (balance > 1 && data < node->left->data) {
        return rightRotate(node);
    }

    // Case 2 - Right Right
    if (balance < -1 && data > node->right->data) {
        return leftRotate(node);
    }

    // Case 3 - Left Right
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Case 4 - Right Left
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}


int main() {
    Node* root = NULL;

    FILE* f = fopen("../../inputs.txt", "r");

    int value;
    while (fscanf(f, "%d", &value) == 1) {
        root = insert(root, value);
    }

    fclose(f);

    return 0;
}
