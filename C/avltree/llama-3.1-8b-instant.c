#include <stdio.h>
#include <stdlib.h>

// Define the structure for an AVL tree node
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Function to calculate the height of a node
int getHeight(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Function to update the height of a node
void updateHeight(Node* node) {
    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));
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

// Function to insert a new node into the AVL tree
Node* insertNode(Node* root, int key) {
    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        root->key = key;
        root->left = root->right = NULL;
        root->height = 1;
        return root;
    }

    if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key);
    } else {
        return root;
    }

    updateHeight(root);

    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1) {
        if (key < root->left->key) {
            return rightRotate(root);
        } else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    if (balanceFactor < -1) {
        if (key > root->right->key) {
            return leftRotate(root);
        } else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

// Function to find the minimum value in the AVL tree
Node* findMin(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to delete a node from the AVL tree
Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    if (root == NULL) {
        return root;
    }

    updateHeight(root);

    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1) {
        if (getBalanceFactor(root->left) >= 0) {
            return rightRotate(root);
        } else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    if (balanceFactor < -1) {
        if (getBalanceFactor(root->right) <= 0) {
            return leftRotate(root);
        } else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

// Function to perform an in-order traversal of the AVL tree
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->key);
        inOrderTraversal(root->right);
    }
}

// Function to perform a pre-order traversal of the AVL tree
void preOrderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform a post-order traversal of the AVL tree
void postOrderTraversal(Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->key);
    }
}

// Function to create an AVL tree from an array of integers
Node* createAVLTree(int arr[], int size) {
    Node* root = NULL;
    for (int i = 0; i < size; i++) {
        root = insertNode(root, arr[i]);
    }
    return root;
}

// Function to test the AVL tree implementation
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