
import random

class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.left = None
        self.right = None
        self.height = 1

class AVLTree:
    def __init__(self):
        self.root = None

    def get_height(self, node):
        if not node:
            return 0
        return node.height

    def update_height(self, node):
        left_height = self.get_height(node.left)
        right_height = self.get_height(node.right)
        node.height = max(left_height, right_height) + 1

    def get_balance(self, node):
        if not node:
            return 0
        return self.get_height(node.left) - self.get_height(node.right)

    def right_rotate(self, node):
        temp = node.left
        node.left = temp.right
        temp.right = node
        self.update_height(node)
        self.update_height(temp)
        return temp

    def left_rotate(self, node):
        temp = node.right
        node.right = temp.left
        temp.left = node
        self.update_height(node)
        self.update_height(temp)
        return temp

    def rebalance(self, node):
        balance = self.get_balance(node)
        if balance > 1:
            if self.get_balance(node.left) >= 0:
                return self.right_rotate(node)
            else:
                node.left = self.left_rotate(node.left)
                return self.right_rotate(node)
        elif balance < -1:
            if self.get_balance(node.right) <= 0:
                return self.left_rotate(node)
            else:
                node.right = self.right_rotate(node.right)
                return self.left_rotate(node)
        return node

    def insert(self, key, value):
        self.root = self._insert(self.root, key, value)

    def _insert(self, node, key, value):
        if not node:
            return Node(key, value)
        if key < node.key:
            node.left = self._insert(node.left, key, value)
        else:
            node.right = self._insert(node.right, key, value)
        self.update_height(node)
        return self.rebalance(node)

    def search(self, key):
        return self._search(self.root, key)

    def _search(self, node, key):
        if not node or node.key == key:
            return node
        if key < node.key:
            return self._search(node.left, key)
        return self._search(node.right, key)

    def delete(self, key):
        self.root = self._delete(self.root, key)

    def _delete(self, node, key):
        if not node:
            return node
        if key < node.key:
            node.left = self._delete(node.left, key)
        elif key > node.key:
            node.right = self._delete(node.right, key)
        else:
            if not node.left and not node.right:
                return None
            elif not node.left:
                return node.right
            elif not node.right:
                return node.left
            else:
                min_node = self._find_min(node.right)
                node.key = min_node.key
                node.value = min_node.value
                node.right = self._delete(node.right, min_node.key)
        if not node:
            return None
        self.update_height(node)
        return self.rebalance(node)

    def _find_min(self, node):
        while node.left:
            node = node.left
        return node

# Example usage with 1000 random inputs
import sys

def main():
    tree = AVLTree()

    # Caminho do arquivo (pode ser passado via linha de comando ou hardcoded)
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            for line in f:
                line = line.strip()
                if line.isdigit():  # apenas inteiros válidos
                    key = int(line)
                    tree.insert(key, f"value_{key}")
    except FileNotFoundError:
        return
if __name__ == "__main__":
    main()
