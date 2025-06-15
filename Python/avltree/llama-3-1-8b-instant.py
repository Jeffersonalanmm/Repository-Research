class Node:
    """Represents a node in the AVL tree."""
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1


class AVLTree:
    """Represents an AVL tree."""
    def __init__(self):
        self.root = None

    def insert(self, key):
        """Inserts a key into the AVL tree."""
        self.root = self._insert(self.root, key)

    def _insert(self, node, key):
        """Recursively inserts a key into the AVL tree."""
        if node is None:
            return Node(key)
        elif key < node.key:
            node.left = self._insert(node.left, key)
        else:
            node.right = self._insert(node.right, key)

        node.height = 1 + max(self._get_height(node.left), self._get_height(node.right))

        balance = self._get_balance(node)

        # Left-left case
        if balance > 1 and key < node.left.key:
            return self._right_rotate(node)

        # Right-right case
        if balance < -1 and key > node.right.key:
            return self._left_rotate(node)

        # Left-right case
        if balance > 1 and key > node.left.key:
            node.left = self._left_rotate(node.left)
            return self._right_rotate(node)

        # Right-left case
        if balance < -1 and key < node.right.key:
            node.right = self._right_rotate(node.right)
            return self._left_rotate(node)

        return node

    def _left_rotate(self, z):
        """Rotates the tree to the left."""
        y = z.right
        T2 = y.left
        y.left = z
        z.right = T2
        z.height = 1 + max(self._get_height(z.left), self._get_height(z.right))
        y.height = 1 + max(self._get_height(y.left), self._get_height(y.right))
        return y

    def _right_rotate(self, z):
        """Rotates the tree to the right."""
        y = z.left
        T3 = y.right
        y.right = z
        z.left = T3
        z.height = 1 + max(self._get_height(z.left), self._get_height(z.right))
        y.height = 1 + max(self._get_height(y.left), self._get_height(y.right))
        return y

    def _get_height(self, node):
        """Gets the height of a node."""
        if node is None:
            return 0
        return node.height

    def _get_balance(self, node):
        """Gets the balance factor of a node."""
        if node is None:
            return 0
        return self._get_height(node.left) - self._get_height(node.right)

    def inorder(self):
        """Performs an inorder traversal of the AVL tree."""
        self._inorder(self.root)

    def _inorder(self, node):
        """Recursively performs an inorder traversal of the AVL tree."""
        if node is not None:
            self._inorder(node.left)
            print(node.key, end=" ")
            self._inorder(node.right)

