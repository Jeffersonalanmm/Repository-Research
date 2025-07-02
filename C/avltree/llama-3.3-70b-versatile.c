#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure for an AVL tree node
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Function to get the height of a node
int getHeight(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Function to update the height of a node
void updateHeight(Node* node) {
    if (node == NULL) {
        return;
    }
    node->height = 1 + ((getHeight(node->left) > getHeight(node->right)) ? getHeight(node->left) : getHeight(node->right));
}

// Function to get the balance factor of a node
int getBalanceFactor(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Function to perform a left rotation
Node* leftRotate(Node* node) {
    Node* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    updateHeight(node);
    updateHeight(temp);
    return temp;
}

// Function to perform a right rotation
Node* rightRotate(Node* node) {
    Node* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    updateHeight(node);
    updateHeight(temp);
    return temp;
}

// Function to rebalance the tree after insertion or deletion
Node* rebalance(Node* node) {
    updateHeight(node);
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1) {
        if (getHeight(node->left->left) >= getHeight(node->left->right)) {
            node = rightRotate(node);
        } else {
            node->left = leftRotate(node->left);
            node = rightRotate(node);
        }
    } else if (balanceFactor < -1) {
        if (getHeight(node->right->right) >= getHeight(node->right->left)) {
            node = leftRotate(node);
        } else {
            node->right = rightRotate(node->right);
            node = leftRotate(node);
        }
    }
    return node;
}

// Function to insert a new node into the AVL tree
Node* insert(Node* node, int key) {
    if (node == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    return rebalance(node);
}

// Function to delete a node from the AVL tree
Node* deleteNode(Node* node, int key) {
    if (node == NULL) {
        return NULL;
    }
    if (key < node->key) {
        node->left = deleteNode(node->left, key);
    } else if (key > node->key) {
        node->right = deleteNode(node->right, key);
    } else {
        if (node->left == NULL) {
            Node* temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            Node* temp = node->left;
            free(node);
            return temp;
        }
        Node* temp = node->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        node->key = temp->key;
        node->right = deleteNode(node->right, temp->key);
    }
    return rebalance(node);
}

// Function to generate 1000 random inputs
void generateRandomInputs(Node** root) {
    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        int key = rand() % 1000;
        *root = insert(*root, key);
    }
}

// Function to delete all nodes from the AVL tree
void deleteAllNodes(Node* node) {
    if (node == NULL) {
        return;
    }
    deleteAllNodes(node->left);
    deleteAllNodes(node->right);
    free(node);
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