#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum Color { RED, BLACK } Color;

typedef struct Node {
    int key;
    int value;
    Color color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

typedef struct {
    Node* root;
    int size;
} Tree;

// Helper function to create a new node
Node* create_node(int key, int value, Color color, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->color = color;
    node->left = NULL;
    node->right = NULL;
    node->parent = parent;
    return node;
}

// Initialize the tree
Tree* tree_create() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

// Rotate left
void rotate_left(Tree* tree, Node* node) {
    Node* temp = node->right;
    node->right = temp->left;
    if (temp->left != NULL) {
        temp->left->parent = node;
    }
    temp->parent = node->parent;
    if (node->parent == NULL) {
        tree->root = temp;
    } else if (node == node->parent->left) {
        node->parent->left = temp;
    } else {
        node->parent->right = temp;
    }
    temp->left = node;
    node->parent = temp;
}

// Rotate right
void rotate_right(Tree* tree, Node* node) {
    Node* temp = node->left;
    node->left = temp->right;
    if (temp->right != NULL) {
        temp->right->parent = node;
    }
    temp->parent = node->parent;
    if (node->parent == NULL) {
        tree->root = temp;
    } else if (node == node->parent->right) {
        node->parent->right = temp;
    } else {
        node->parent->left = temp;
    }
    temp->right = node;
    node->parent = temp;
}

// Fix the tree after insertion
void insertion_fix(Tree* tree, Node* node) {
    while (node->parent != NULL && node->parent->color == RED) {
        Node* grandparent = node->parent->parent;
        if (node->parent == grandparent->left) {
            Node* uncle = grandparent->right;
            if (uncle != NULL && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    rotate_left(tree, node);
                }
                node->parent->color = BLACK;
                grandparent->color = RED;
                rotate_right(tree, grandparent);
            }
        } else {
            Node* uncle = grandparent->left;
            if (uncle != NULL && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rotate_right(tree, node);
                }
                node->parent->color = BLACK;
                grandparent->color = RED;
                rotate_left(tree, grandparent);
            }
        }
    }
    tree->root->color = BLACK;
}

// Insert a new key-value pair into the tree
void tree_insert(Tree* tree, int key, int value) {
    Node* node = create_node(key, value, RED, NULL);
    if (tree->root == NULL) {
        tree->root = node;
        tree->size++;
        return;
    }

    Node* current = tree->root;
    Node* parent = NULL;
    while (current != NULL) {
        parent = current;
        if (node->key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    node->parent = parent;
    if (node->key < parent->key) {
        parent->left = node;
    } else {
        parent->right = node;
    }
    tree->size++;

    insertion_fix(tree, node);
}

// Search for a key in the tree
int tree_search(Tree* tree, int key) {
    Node* current = tree->root;
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return -1; // Key not found
}

int main() {
    srand(time(NULL));
    Tree* tree = tree_create();
    
    // Insert 1000 random keys
    for (int i = 0; i < 1000; i++) {
        int key = rand() % 10000;
        tree_insert(tree, key, key);
    }
    
    // Search for some keys
    int search_keys[] = {1234, 5678, 9123, 4567};
    for (int key : search_keys) {
        int result = tree_search(tree, key);
    }
    
    // Delete some keys
    int delete_keys[] = {1234, 5678};
    for (int key : delete_keys) {
        // Implementation of tree_delete would go here
    }
    
    return 0;
}