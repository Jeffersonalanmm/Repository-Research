#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

typedef struct Node {
    int data;
    int color;
    struct Node *left, *right, *parent;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

void leftRotate(Node** root, Node*& pt) {
    Node* pt_right = pt->right;
    pt->right = pt_right->left;
    if (pt->right != NULL)
        pt->right->parent = pt;
    pt_right->parent = pt->parent;
    if (pt->parent == NULL)
        *root = pt_right;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
    else
        pt->parent->right = pt_right;
    pt_right->left = pt;
    pt->parent = pt_right;
}

void rightRotate(Node** root, Node*& pt) {
    Node* pt_left = pt->left;
    pt->left = pt_left->right;
    if (pt->left != NULL)
        pt->left->parent = pt;
    pt_left->parent = pt->parent;
    if (pt->parent == NULL)
        *root = pt_left;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
    else
        pt->parent->right = pt_left;
    pt_left->right = pt;
    pt->parent = pt_left;
}

void fixViolation(Node** root, Node* pt) {
    Node* parent_pt = NULL;
    Node* grand_parent_pt = NULL;

    while ((pt != *root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        if (parent_pt == grand_parent_pt->left) {
            Node* uncle_pt = grand_parent_pt->right;

            if (uncle_pt != NULL && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->right) {
                    leftRotate(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                rightRotate(root, grand_parent_pt);
            }
        } else {
            Node* uncle_pt = grand_parent_pt->left;

            if ((uncle_pt != NULL) && (uncle_pt->color == RED)) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->left) {
                    rightRotate(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                leftRotate(root, grand_parent_pt);
            }
        }
    }
    (*root)->color = BLACK;
}

void insert(Node** root, int data) {
    Node* pt = *root;
    Node* pt_parent = NULL;

    while (pt != NULL) {
        pt_parent = pt;
        if (data < pt->data)
            pt = pt->left;
        else
            pt = pt->right;
    }

    Node* newNode = createNode(data);
    newNode->parent = pt_parent;
    if (pt_parent == NULL)
        *root = newNode;
    else if (newNode->data < pt_parent->data)
        pt_parent->left = newNode;
    else
        pt_parent->right = newNode;

    fixViolation(root, newNode);
}

Node* search(Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (root->data > data)
        return search(root->left, data);

    return search(root->right, data);
}

void inorderHelper(Node* root, int* arr, int* index) {
    if (root != NULL) {
        inorderHelper(root->left, arr, index);
        arr[(*index)++] = root->data;
        inorderHelper(root->right, arr, index);
    }
}

void inorder(Node* root, int* arr) {
    int index = 0;
    inorderHelper(root, arr, &index);
}

int main() {
    Node* root = NULL;
    int arr[1000];
    int index = 0;

    // Insert 1000 random integers into the Red-Black Tree
    for (int i = 0; i < 1000; i++) {
        int random_data = rand() % 10000; // Random data between 0 and 9999
        insert(&root, random_data);
    }

    // Inorder traversal to verify the tree structure
    inorder(root, arr);

    // Free the allocated memory for the tree nodes
    // (Implementation of freeTree function is omitted for brevity)

    return 0;
}
