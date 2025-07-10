

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1  # default height for a new node is 1 (since it's a leaf initially)

class AVLTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        # Private function to insert
        self.root = self._insert(self.root, key)

    def _insert(self, node, key):
        if not node:
            return Node(key)
        if key < node.key:
            node.left = self._insert(node.left, key)
        else:
            node.right = self._insert(node.right, key)

        # Update height
        node.height = 1 + max(self._get_height(node.left), self._get_height(node.right))

        # Get balance factor
        balance = self._get_balance(node)

        # Now, check if unbalanced and perform rotations
        # Case 1 - Left Left
        if balance > 1 and key < node.left.key:
            return self._right_rotate(node)
        # Case 2 - Right Right
        if balance < -1 and key > node.right.key:
            return self._left_rotate(node)
        # Case 3 - Left Right
        if balance > 1 and key > node.left.key:
            node.left = self._left_rotate(node.left)
            return self._right_rotate(node)
        # Case 4 - Right Left
        if balance < -1 and key < node.right.key:
            node.right = self._right_rotate(node.right)
            return self._left_rotate(node)
        return node


def _left_rotate(self, z):
    y = z.right
    T2 = y.left
    y.left = z
    z.right = T2

    # Update heights
    z.height = 1 + max(self._get_height(z.left), self._get_height(z.right))
    y.height = 1 + max(self._get_height(y.left), self._get_height(y.right))

    return y  # new root of the subtree


def _right_rotate(self, y):
    x = y.left
    T2 = x.right
    x.right = y
    y.left = T2

    # Update heights
    y.height = 1 + max(self._get_height(y.left), self._get_height(y.right))
    x.height = 1 + max(self._get_height(x.left), self._get_height(x.right))

    return x

def _get_height(self, node):
    if not node:
        return 0
    return node.height

def _get_balance(self, node):
    if not node:
        return 0
    return self._get_height(node.left) - self._get_height(node.right)


def delete(self, key):
    self.root = self._delete_node(self.root, key)

def _delete_node(self, node, key):
    if not node:
        return node

    # Step 1 - BST delete
    if key < node.key:
        node.left = self._delete_node(node.left, key)
    elif key > node.key:
        node.right = self._delete_node(node.right, key)
    else:
        # Node to delete found
        if node.left is None:
            temp = node.right
            node = None
            return temp
        elif node.right is None:
            temp = node.left
            node = None
            return temp

        # Node has two children: get the inorder successor (min in right subtree)
        temp = self._min_value_node(node.right)
        node.key = temp.key
        node.right = self._delete_node(node.right, temp.key)

    if node is None:
        return node

    # Update height
    node.height = 1 + max(self._get_height(node.left), self._get_height(node.right))

    # Get balance factor
    balance = self._get_balance(node)

    # Now, four cases for rebalancing

    # Case 1 - Left Left
    if balance > 1 and self._get_balance(node.left) >= 0:
        return self._right_rotate(node)
    # Case 2 - Left Right
    if balance > 1 and self._get_balance(node.left) < 0:
        node.left = self._left_rotate(node.left)
        return self._right_rotate(node)
    # Case 3 - Right Right
    if balance < -1 and self._get_balance(node.right) <=0:
        return self._left_rotate(node)
    # Case 4 - Right Left
    if balance < -1 and self._get_balance(node.right) >0:
        node.right = self._right_rotate(node.right)
        return self._left_rotate(node)

    return node


def _min_value_node(self, node):
    current = node
    while current.left is not None:
        current = current.left
    return current


if balance >1 and key < node.left.key:  # left-left
    return right_rotate(node)

import random

if __name__ == "__main__":
    tree = AVLTree()
    for _ in range(1000):
        key = random.randint(1, 10000)
        tree.insert(key)

class AVLTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        self.root = self._insert(self.root, key)

    def _insert(self, node, key):
        if not node:
            return Node(key)
        if key < node.key:
            node.left = self._insert(node.left, key)
        else:
            node.right = self._insert(node.right, key)

        # Update height
        node.height = 1 + max(self._get_height(node.left), self._get_height(node.right))

        balance = self._get_balance(node)

        # Left Left
        if balance > 1 and key < node.left.key:
            return self._right_rotate(node)
        # Right Right
        if balance < -1 and key > node.right.key:
            return self._left_rotate(node)
        # Left Right
        if balance > 1 and key > node.left.key:
            node.left = self._left_rotate(node.left)
            return self._right_rotate(node)
        # Right Left
        if balance < -1 and key < node.right.key:
            node.right = self._right_rotate(node.right)
            return self._left_rotate(node)
        return node

def _left_rotate(self, z):
    y = z.right
    T2 = y.left
    y.left = z
    z.right = T2

    # Update heights
    z.height = 1 + max(self._get_height(z.left), self._get_height(z.right))
    y.height = 1 + max(self._get_height(y.left), self._get_height(y.right))
    return y

def _right_rotate(self, y):
    x = y.left
    T2 = x.right
    x.right = y
    y.left = T2

    # Update heights
    y.height = 1 + max(self._get_height(y.left), self._get_height(y.right))
    x.height = 1 + max(self._get_height(x.left, self._get_height(x.right))
    return x

def delete(self, key):
    self.root = self._delete_node(self.root, key)

def _delete_node(self, node, key):
    if not node:
        return node

    # Step 1 - BST delete
    if key < node.key:
        node.left = self._delete_node(node.left, key)
    elif key > node.key:
        node.right = self._delete_node(node.right, key)
    else:
        # Node to delete has 0 or 1 child
        if node.left is None:
            temp = node.right
            node = None
            return temp
        elif node.right is None:
            temp = node.left
            node = None
            return temp

        # Node has two children: get the inorder successor
        temp = self._min_value_node(node.right)
        node.key = temp.key
        node.right = self._delete_node(node.right, temp.key)

    if node is None:
        return node

    # Update height
    node.height = 1 + max(self._get_height(node.left), self._get_height(node.right))

    balance = self._get_balance(node)

    # Now, check balance and rotate
    # Case 1 - Left Left
    if balance > 1 and self._get_balance(node.left) >=0:
        return self._right_rotate(node)
    # Case 2 - Left Right
    if balance >1 and self._get_balance(node.left) <0:
        node.left = self._left_rotate(node.left)
        return self._right_rotate(node)
    # Case 3 - Right Right
    if balance < -1 and self._get_balance(node.right) <=0:
        return self._left_rotate(node)
    # Case4 - Right Left
    if balance < -1 and self._get_balance(node.right) >0:
        node.right = self._right_rotate(node.right)
        return self._left_rotate(node)
    return node


if __name__ == "__main__":
    import random
    tree = AVLTree()
    for _ in range(1000):
        key = random.randint(1, 10000)
        tree.insert(key)


def _left_rotate(self, z):
    y = z.right
    T2 = y.left
    y.left = z
    z.right = T2

    z.height = 1 + max( self._get_height(z.left), self._get_height(z.right) )
    y.height = 1 + max( self._get_height(y.left), self._get_height(y.right) )
    return y


def _left_rotate(self, z):
    y = z.right
    T2 = y.left
    y.left = z
    z.right = T2

    z.height = 1 + max( self._get_height(z.left), self._get_height(z.right) )
    y.height = 1 + max( self._get_height(y.left), self._get_height(y.right) )
    return y


if balance > 1:
    if key < node.left.key:
        return self._right_rotate(node)
    else:
        # left-right case
        node.left = self._left_rotate(node.left)
        return self._right_rotate(node)
elif balance < -1:
    if key > node.right.key:
        return self._left_rotate(node)
    else:
        node.right = self._right_rotate(node.right)
        return self._left_rotate(node)
return node

if balance > 1:
    if key < node.left.key:
        # left-left
        return self._right_rotate(node)
    else:
        # left-right
        node.left = self._left_rotate(node.left)
        return self._right_rotate(node)
elif balance < -1:
    if key > node.right.key:
        # right-right
        return self._left_rotate(node)
    else:
        # right-left
        node.right = self._right_rotate(node.right)
        return self._left_rotate(node)
return node

balance = self._get_balance(node)

if balance > 1:
    if key < node.left.key:
        return self._right_rotate(node)
    else:
        node.left = self._left_rotate(node.left)
        return self._right_rotate(node)
elif balance < -1:
    if key > node.right.key:
        return self._left_rotate(node)
    else:
        node.right = self._right_rotate(node.right)
        return self._left_rotate(node)
return node

def _get_height(self, node):
    if not node:
        return 0
    return node.height

def _get_balance(self, node):
    if not node:
        return 0
    return self._get_height(node.left) - self._get_height(node.right)

def _left_rotate(self, z):
    y = z.right
    T2 = y.left
    y.left = z
    z.right = T2

    z.height = 1 + max( self._get_height(z.left), self._get_height(z.right) )
    y.height = 1 + max( self._get_height(y.left, self._get_height(y.right) )
    return y


def _left_rotate(self, z):
    y = z.right
    T2 = y.left
    y.left = z
    z.right = T2

    z.height = 1 + max( self._get_height(z.left), self._get_height(z.right) )
    y.height = 1 + max( self._get_height(y.left), self._get_height(y.right) )
    return y
