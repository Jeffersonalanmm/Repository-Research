#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

int get_height(Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

int get_balance(Node* node) {
    if (node == NULL) return 0;
    return get_height(node->left) - get_height(node->right);
}

Node* create_node(int key) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node* right_rotate(Node* node) {
    Node* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node->height = 1 + (get_height(node->left) > get_height(node->right) ? get_height(node->left) : get_height(node->right));
    temp->height = 1 + (get_height(temp->left) > get_height(temp->right) ? get_height(temp->left) : get_height(temp->right));
    return temp;
}

Node* left_rotate(Node* node) {
    Node* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node->height = 1 + (get_height(node->left) > get_height(node->right) ? get_height(node->left) : get_height(node->right));
    temp->height = 1 + (get_height(temp->left) > get_height(temp->right) ? get_height(temp->left) : get_height(temp->right));
    return temp;
}

Node* insert(Node* node, int key) {
    if (node == NULL) return create_node(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    else return node;

    node->height = 1 + (get_height(node->left) > get_height(node->right) ? get_height(node->left) : get_height(node->right));

    int balance = get_balance(node);

    if (balance > 1 && key < node->left->key) return right_rotate(node);
    if (balance < -1 && key > node->right->key) return left_rotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

Node* find_min(Node* node) {
    while (node->left != NULL) node = node->left;
    return node;
}

Node* delete_node(Node* node, int key) {
    if (node == NULL) return node;
    if (key < node->key) node->left = delete_node(node->left, key);
    else if (key > node->key) node->right = delete_node(node->right, key);
    else {
        if (node->left == NULL) {
            Node* temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            Node* temp = node->left;
            free(node);
            return temp;
        }
        Node* temp = find_min(node->right);
        node->key = temp->key;
        node->right = delete_node(node->right, temp->key);
    }

    if (node == NULL) return node;

    node->height = 1 + (get_height(node->left) > get_height(node->right) ? get_height(node->left) : get_height(node->right));

    int balance = get_balance(node);

    if (balance > 1 && get_balance(node->left) >= 0) return right_rotate(node);
    if (balance < -1 && get_balance(node->right) <= 0) return left_rotate(node);
    if (balance > 1 && get_balance(node->left) < 0) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    if (balance < -1 && get_balance(node->right) > 0) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

void free_tree(Node* node) {
    if (node == NULL) return;
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

int main() {
    srand(time(NULL));
    Node* root = NULL;
    for (int i = 0; i < 1000; i++) {
        int key = rand() % 10000;
        root = insert(root, key);
    }
    for (int i = 0; i < 500; i++) {
        int key = rand() % 10000;
        root = delete_node(root, key);
    }
    free_tree(root);
    return 0;
}