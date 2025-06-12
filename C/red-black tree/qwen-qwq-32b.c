#include <stdlib.h>
#include <time.h>

struct rb_node {
    int key;
    enum color {RED, BLACK} color;
    struct rb_node *left, *right, *parent;
};


typedef enum { RED, BLACK } color;

struct rb_node {
    int key;
    color color;
    struct rb_node *left, *right, *parent;
};

void left_rotate(struct rb_node **nodeptr, struct rb_node *x) {
    struct rb_node *y = x->right;
    x->right = y->left;
    if (y->left != nil) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x == *nodeptr) {
        *nodeptr = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

oid insert_fixup(struct rb_node **root, struct rb_node *node) {
    while (node->parent->color == RED) {
        if (node->parent == node->parent->parent->left) {
            struct rb_node *uncle = node->parent->parent->right;
            if (uncle->color == RED) {
                // Case 1: uncle is red
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    // Case 2: right-left case, need to rotate left on parent
                    node = node->parent;
                    left_rotate(root, node);
                }
                // Case 3: left case, rotate right on grandparent
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                right_rotate(root, node->parent->parent);
            }
        } else {
            // mirror the above for the other side
            // similar code for when parent is the right child of grandparent
            // mirror the code above
        }
    }
    (*root)->color = BLACK; // Ensure root is black
}

while (node != *root && node->parent->color == RED) {
    if (node->parent == node->parent->parent->left) { // parent is left child of grandparent
        struct rb_node *uncle = node->parent->parent->right;
        if (uncle->color == RED) {
            // case 1: uncle is red
            node->parent->color = BLACK;
            uncle->color = BLACK;
            node->parent->parent->color = RED;
            node = node->parent->parent;
        } else {
            // uncle is black
            if (node == node->parent->right) {
                // case 2: node is right child of parent
                node = node->parent;
                left_rotate(root, node);
            }
            // case 3: node is left child of parent
            node->parent->color = BLACK;
            node->parent->parent->color = RED;
            right_rotate(root, node->parent->parent);
        }
    } else { // parent is right child of grandparent
        // mirror the above code with left and right swapped
        struct rb_node *uncle = node->parent->parent->left;
        if (uncle->color == RED) {
            node->parent->color = BLACK;
            uncle->color = BLACK;
            node->parent->parent->color = RED;
            node = node->parent->parent;
        } else {
            if (node == node->parent->left) {
                node = node->parent;
                right_rotate(root, node);
            }
            node->parent->color = BLACK;
            node->parent->parent->color = RED;
            left_rotate(root, node->parent->parent);
        }
    }
}
// color the root black
if (node == *root)
    node->color = BLACK;

    struct rb_node *insert_node(struct rb_node **root, int key) {
    struct rb_node *y = nil;
    struct rb_node *x = *root;
    struct rb_node *new_node = (struct rb_node*)malloc(sizeof(struct rb_node));
    new_node->key = key;
    new_node->left = nil;
    new_node->right = nil;
    new_node->color = RED;

    while (x != nil) {
        y = x;
        if (new_node->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    new_node->parent = y;
    if (y == nil)
        *root = new_node;
    else {
        if (new_node->key < y->key)
            y->left = new_node;
        else
            y->right = new_node;
    }
    insert_fixup(root, new_node);
    return new_node;
}

void insert_fixup(struct rb_node **root, struct rb_node *node) {
    while (node != *root && node->parent->color == RED) {
        if (node->parent == node->parent->parent->left) { // parent is left child
            struct rb_node *uncle = node->parent->parent->right;
            if (uncle->color == RED) {
                // case 1: uncle is red
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    // case 2: node is right child, rotate left
                    node = node->parent;
                    left_rotate(root, node);
                }
                // case 3: rotate right on grandparent
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                right_rotate(root, node->parent->parent);
            }
        } else { // parent is right child of grandparent
            struct rb_node *uncle = node->parent->parent->left;
            if (uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    right_rotate(root, node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                left_rotate(root, node->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

int main() {
    init_nil();
    struct rb_node *root = nil;
    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        int key = rand() % 10000;
        insert(&root, key);
    }
    // no need to free, since no prints, but memory leak is okay for the test.

    return 0;
}