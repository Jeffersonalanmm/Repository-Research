#include <stdio.h>
#include <stdlib.h>

// Define the structure for an AVL Tree node
typedef struct Node {
    int key;
    void* value;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Function to create a new AVL Tree node
Node* createNode(int key, void* value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        return NULL; // Memory error
    }
    newNode->key = key;
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    newNode->height = 1; // Height of a leaf node is 1
    return newNode;
}

// Function to get the height of a node
int getHeight(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Function to update the height of a node
void updateHeight(Node* node) {
    node->height = 1 + ((getHeight(node->left) > getHeight(node->right)) ?
        getHeight(node->left) : getHeight(node->right));
}

// Function to get the balance factor of a node
int getBalance(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Right rotation
Node* rightRotate(Node* root) {
    Node* temp = root->left;
    Node* tempRight = temp->right;

    // Rotate
    temp->right = root;
    root->left = tempRight;

    // Update heights
    updateHeight(root);
    updateHeight(temp);

    // The new root is temp
    return temp;
}

// Left rotation
Node* leftRotate(Node* root) {
    Node* temp = root->right;
    Node* tempLeft = temp->left;

    // Rotate
    temp->left = root;
    root->right = tempLeft;

    // Update heights
    updateHeight(root);
    updateHeight(temp);

    // The new root is temp
    return temp;
}

// Function to insert a new node into the AVL Tree
Node* insertNode(Node* root, int key, void* value) {
    // Perform normal BST insertion
    if (root == NULL) {
        return createNode(key, value);
    }

    if (key < root->key) {
        root->left = insertNode(root->left, key, value);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key, value);
    } else {
        // Duplicate keys are not allowed
        return root;
    }

    // Update the height of the current node
    updateHeight(root);

    // Check balance factor
    int balance = getBalance(root);

    // Left-left or left-right imbalance
    if (balance > 1) {
        if (key < root->left->key) {
            // Left-left case: Right rotation
            return rightRotate(root);
        } else {
            // Left-right case: Left-right rotation
            root->left = leftRotate(root->left);
            updateHeight(root);
            return rightRotate(root);
        }
    }

    // Right-right or right-left imbalance
    if (balance < -1) {
        if (key > root->right->key) {
            // Right-right case: Left rotation
            return leftRotate(root);
        } else {
            // Right-left case: Right-left rotation
            root->right = rightRotate(root->right);
            updateHeight(root);
            return leftRotate(root);
        }
    }

    return root; // Tree is balanced
}

// Function to find the node with the minimum key in the tree
Node* findMin(Node* root) {
    Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the AVL Tree
Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root; // Key not found
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to delete found
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the minimum node in the right subtree
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->key);
    }

    // If the tree becomes empty
    if (root == NULL) {
        return root;
    }

    // Update the height of the current node
    updateHeight(root);

    // Check balance factor
    int balance = getBalance(root);

    // Left-left or left-right imbalance
    if (balance > 1) {
        if (getBalance(root->left) >= 0) {
            // Left-left case: Right rotation
            return rightRotate(root);
        } else {
            // Left-right case: Left-right rotation
            root->left = leftRotate(root->left);
            updateHeight(root);
            return rightRotate(root);
        }
    }

    // Right-right or right-left imbalance
    if (balance < -1) {
        if (getBalance(root->right) <= 0) {
            // Right-right case: Left rotation
            return leftRotate(root);
        } else {
            // Right-left case: Right-left rotation
            root->right = rightRotate(root->right);
            updateHeight(root);
            return leftRotate(root);
        }
    }

    return root; // Tree is balanced
}

// Function to search for a key in the AVL Tree
void* search(Node* root, int key) {
    if (root == NULL) {
        return NULL; // Key not found
    }

    if (key < root->key) {
        return search(root->left, key);
    } else if (key > root->key) {
        return search(root->right, key);
    } else {
        return root->value; // Key found
    }
}

// Function to perform in-order traversal of the AVL Tree
void inOrderTraversal(Node* root, void (*callback)(int key, void* value)) {
    if (root != NULL) {
        inOrderTraversal(root->left, callback);
        callback(root->key, root->value);
        inOrderTraversal(root->right, callback);
    }
}

// Function to perform pre-order traversal of the AVL Tree
void preOrderTraversal(Node* root, void (*callback)(int key, void* value)) {
    if (root != NULL) {
        callback(root->key, root->value);
        preOrderTraversal(root->left, callback);
        preOrderTraversal(root->right, callback);
    }
}

// Function to perform post-order traversal of the AVL Tree
void postOrderTraversal(Node* root, void (*callback)(int key, void* value)) {
    if (root != NULL) {
        postOrderTraversal(root->left, callback);
        postOrderTraversal(root->right, callback);
        callback(root->key, root->value);
    }
}
// Function to print key and value (for traversal)
void printKeyAndValue(int key, void* value) {
    printf("Key: %d\n", key);
}

// Example usage in main function
int main() {
    Node* root = NULL;

    FILE* f = fopen("../../inputs.txt", "r");

    int value;
    while (fscanf(f, "%d", &value) == 1) {
        root = insertNode(root, value, NULL);
    }

    fclose(f);
    return 0;
}
