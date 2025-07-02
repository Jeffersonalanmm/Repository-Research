#include <stdio.h>
#include <stdlib.h>

// Define the color of a node
typedef enum {
    RED,
    BLACK
} Color;

// Define the structure of a node
typedef struct Node {
    int key;
    Color color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

// Define the structure of the Red-Black Tree
typedef struct {
    Node* root;
} RedBlackTree;

// Function to create a new node
Node* newNode(int key) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->key = key;
    node->color = RED;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

// Function to get the parent of a node
Node* get_parent(Node* node) {
    return node->parent;
}

// Function to get the left child of a node
Node* get_left_child(Node* node) {
    return node->left;
}

// Function to get the right child of a node
Node* get_right_child(Node* node) {
    return node->right;
}

// Function to get the grandparent of a node
Node* get_grandparent(Node* node) {
    Node* parent = get_parent(node);
    if (parent == NULL) {
        return NULL;
    }
    return get_parent(parent);
}

// Function to get the uncle of a node
Node* get_uncle(Node* node) {
    Node* parent = get_parent(node);
    Node* grandparent = get_grandparent(node);
    if (grandparent == NULL) {
        return NULL;
    }
    if (parent == get_left_child(grandparent)) {
        return get_right_child(grandparent);
    } else {
        return get_left_child(grandparent);
    }
}

// Function to get the sibling of a node
Node* get_sibling(Node* node) {
    Node* parent = get_parent(node);
    if (parent == NULL) {
        return NULL;
    }
    if (node == get_left_child(parent)) {
        return get_right_child(parent);
    } else {
        return get_left_child(parent);
    }
}

// Function to rotate left
void rotate_left(Node** root, Node* node) {
    Node* parent = get_parent(node);
    Node* grandparent = get_grandparent(node);
    Node* sibling = get_sibling(node);
    Node* new_root = sibling;
    node->parent = new_root;
    if (new_root == get_left_child(parent)) {
        parent->left = node;
    } else {
        parent->right = node;
    }
    node->left = sibling->right;
    if (sibling->right != NULL) {
        sibling->right->parent = node;
    }
    sibling->right = node->left;
    node->left = new_root;
    if (new_root == get_left_child(grandparent)) {
        grandparent->left = new_root;
    } else {
        grandparent->right = new_root;
    }
    new_root->parent = parent;
    if (parent == NULL) {
        *root = new_root;
    }
}

// Function to rotate right
void rotate_right(Node** root, Node* node) {
    Node* parent = get_parent(node);
    Node* grandparent = get_grandparent(node);
    Node* sibling = get_sibling(node);
    Node* new_root = sibling;
    node->parent = new_root;
    if (new_root == get_right_child(parent)) {
        parent->right = node;
    } else {
        parent->left = node;
    }
    node->right = sibling->left;
    if (sibling->left != NULL) {
        sibling->left->parent = node;
    }
    sibling->left = node->right;
    node->right = new_root;
    if (new_root == get_right_child(grandparent)) {
        grandparent->right = new_root;
    } else {
        grandparent->left = new_root;
    }
    new_root->parent = parent;
    if (parent == NULL) {
        *root = new_root;
    }
}

// Function to insert a node
void insert(Node** root, int key) {
    Node* node = newNode(key);
    Node* parent = NULL;
    Node* current = *root;
    while (current != NULL) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    node->parent = parent;
    if (parent == NULL) {
        *root = node;
    } else if (key < parent->key) {
        parent->left = node;
    } else {
        parent->right = node;
    }
    if (node->parent == NULL) {
        node->color = BLACK;
        return;
    }
    if (node->parent->parent == NULL) {
        return;
    }
    if (node->parent->color == BLACK) {
        return;
    }
    Node* uncle = get_uncle(node);
    if (uncle != NULL && uncle->color == RED) {
        node->parent->color = BLACK;
        uncle->color = BLACK;
        node->parent->parent->color = RED;
        node = node->parent->parent;
    } else {
        if (node == get_right_child(node->parent) && node->parent == get_left_child(node->parent->parent)) {
            node = node->parent;
            rotate_left(root, node);
        } else if (node == get_left_child(node->parent) && node->parent == get_right_child(node->parent->parent)) {
            node = node->parent;
            rotate_right(root, node);
        }
        node->parent->color = BLACK;
        node->parent->parent->color = RED;
        if (node == get_right_child(node->parent)) {
            rotate_left(root, node->parent->parent);
        } else {
            rotate_right(root, node->parent->parent);
        }
    }
}

// Function to fix the tree after insertion
void fix_tree(Node** root) {
    Node* node = *root;
    while (node != NULL && node->parent != NULL && node->parent->color == RED) {
        if (node->parent == get_left_child(get_parent(node->parent))) {
            Node* uncle = get_right_child(get_parent(node->parent));
            if (uncle != NULL && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                get_parent(node->parent)->color = RED;
                node = get_parent(node->parent);
            } else {
                if (node == get_right_child(node->parent)) {
                    node = node->parent;
                    rotate_left(root, node);
                }
                node->parent->color = BLACK;
                get_parent(node->parent)->color = RED;
                rotate_right(root, get_parent(node->parent));
            }
        } else {
            Node* uncle = get_left_child(get_parent(node->parent));
            if (uncle != NULL && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                get_parent(node->parent)->color = RED;
                node = get_parent(node->parent);
            } else {
                if (node == get_left_child(node->parent)) {
                    node = node->parent;
                    rotate_right(root, node);
                }
                node->parent->color = BLACK;
                get_parent(node->parent)->color = RED;
                rotate_left(root, get_parent(node->parent));
            }
        }
    }
    (*root)->color = BLACK;
}

// Function to get the height of a node
int get_height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + (get_height(node->left) > get_height(node->right) ? get_height(node->left) : get_height(node->right));
}

// Function to get the balance factor of a node
int get_balance_factor(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return get_height(node->left) - get_height(node->right);
}

// Function to rebalance the tree
void rebalance_tree(Node** root) {
    Node* node = *root;
    while (node != NULL) {
        node->left = balance(node->left);
        node->right = balance(node->right);
        node = node->parent;
    }
    *root = balance(*root);
}

// Function to balance a node
Node* balance(Node* node) {
    if (node == NULL) {
        return node;
    }
    int balance_factor = get_balance_factor(node);
    if (balance_factor > 1) {
        if (get_height(node->left->left) >= get_height(node->left->right)) {
            rotate_right(&node, node->left);
        } else {
            rotate_left(&node, node->left->left);
            rotate_right(&node, node->left);
        }
    } else if (balance_factor < -1) {
        if (get_height(node->right->right) >= get_height(node->right->left)) {
            rotate_left(&node, node->right);
        } else {
            rotate_right(&node, node->right->right);
            rotate_left(&node, node->right);
        }
    }
    return node;
}

// Function to insert a node and rebalance the tree
void insert_and_rebalance(RedBlackTree* tree, int key) {
    insert(&tree->root, key);
    fix_tree(&tree->root);
    rebalance_tree(&tree->root);
}

// Function to test the Red-Black Tree
void test_red_black_tree() {
    RedBlackTree tree;
    tree.root = NULL;
    for (int i = 0; i < 1000; i++) {
        insert_and_rebalance(&tree, i);
    }
}

int main() {
    FILE* file = fopen("../../inputs.txt", "r");
    if (!file) {
        fprintf(stderr, "Erro ao abrir o arquivo '../../inputs.txt'\n");
        return 1;
    }

    RedBlackTree tree;
    tree.root = NULL;

    int key;
    int count = 0;
    while (count < 1000 && fscanf(file, "%d", &key) == 1) {
        insert_and_rebalance(&tree, key);
        count++;
    }

    fclose(file);
    printf("Inserção completa: %d chaves adicionadas à árvore rubro-negra.\n", count);
    return 0;
}
