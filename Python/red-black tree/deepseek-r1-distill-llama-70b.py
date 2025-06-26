
import random

class Node:
    def __init__(self, key, value, color='red'):
        self.key = key
        self.value = value
        self.color = color
        self.left = None
        self.right = None
        self.parent = None

class RedBlackTree:
    def __init__(self):
        self.root = None

    def insert(self, key, value):
        node = Node(key, value)
        if not self.root:
            node.color = 'black'
            self.root = node
            return
        current = self.root
        while True:
            if key < current.key:
                if not current.left:
                    current.left = node
                    node.parent = current
                    break
                current = current.left
            else:
                if not current.right:
                    current.right = node
                    node.parent = current
                    break
                current = current.right
        if node.parent.parent:
            self.fix_insert(node)

    def fix_insert(self, node):
        while node.parent.color == 'red':
            grandparent = node.parent.parent
            if node.parent == grandparent.left:
                uncle = grandparent.right
                if uncle and uncle.color == 'red':
                    node.parent.color = 'black'
                    uncle.color = 'black'
                    grandparent.color = 'red'
                    node = grandparent
                else:
                    if node == node.parent.right:
                        node = node.parent
                        self.left_rotate(node)
                    node.parent.color = 'black'
                    grandparent.color = 'red'
                    node = grandparent
                    self.right_rotate(node)
            else:
                uncle = grandparent.left
                if uncle and uncle.color == 'red':
                    node.parent.color = 'black'
                    uncle.color = 'black'
                    grandparent.color = 'red'
                    node = grandparent
                else:
                    if node == node.parent.left:
                        node = node.parent
                        self.right_rotate(node)
                    node.parent.color = 'black'
                    grandparent.color = 'red'
                    node = grandparent
                    self.left_rotate(node)
        self.root.color = 'black'

    def delete(self, key):
        node = self.find(key)
        if not node:
            return
        temp = node
        temp_color = temp.color
        if not node.left:
            self.rb_transplant(node, node.right)
        elif not node.right:
            self.rb_transplant(node, node.left)
        else:
            temp = self.tree_min(node.right)
            temp_color = temp.color
            if temp.parent != node:
                self.rb_transplant(temp, temp.right)
                temp.right = node.right
                temp.right.parent = temp
            self.rb_transplant(node, temp)
            temp.left = node.left
            temp.left.parent = temp
        if temp_color == 'black':
            self.delete_fix(temp)

    def delete_fix(self, node):
        while node != self.root and node.color == 'black':
            if node == node.parent.left:
                sibling = node.parent.right
                if sibling.color == 'red':
                    sibling.color = 'black'
                    node.parent.color = 'red'
                    self.left_rotate(node.parent)
                    sibling = node.parent.right
                if sibling.left.color == 'black' and sibling.right.color == 'black':
                    sibling.color = 'red'
                    node = node.parent
                else:
                    if sibling.right.color == 'black':
                        sibling.left.color = 'black'
                        sibling.color = 'red'
                        self.right_rotate(sibling)
                    sibling.color = node.parent.color
                    node.parent.color = 'black'
                    sibling.right.color = 'black'
                    self.left_rotate(node.parent)
                    node = self.root
            else:
                sibling = node.parent.left
                if sibling.color == 'red':
                    sibling.color = 'black'
                    node.parent.color = 'red'
                    self.right_rotate(node.parent)
                    sibling = node.parent.left
                if sibling.left.color == 'black' and sibling.right.color == 'black':
                    sibling.color = 'red'
                    node = node.parent
                else:
                    if sibling.left.color == 'black':
                        sibling.right.color = 'black'
                        sibling.color = 'red'
                        self.left_rotate(sibling)
                    sibling.color = node.parent.color
                    node.parent.color = 'black'
                    sibling.left.color = 'black'
                    self.right_rotate(node.parent)
                    node = self.root
        node.color = 'black'

    def rb_transplant(self, u, v):
        if not u.parent:
            self.root = v
        elif u == u.parent.left:
            u.parent.left = v
        else:
            u.parent.right = v
        v.parent = u.parent

    def tree_min(self, node):
        while node.left:
            node = node.left
        return node

    def find(self, key):
        current = self.root
        while current and current.key != key:
            if key < current.key:
                current = current.left
            else:
                current = current.right
        return current

    def left_rotate(self, x):
        y = x.right
        x.right = y.left
        if y.left:
            y.left.parent = x
        y.parent = x.parent
        if not x.parent:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def right_rotate(self, x):
        y = x.left
        x.left = y.right
        if y.right:
            y.right.parent = x
        y.parent = x.parent
        if not x.parent:
            self.root = y
        elif x == x.parent.right:
            x.parent.right = y
        else:
            x.parent.left = y
        y.right = x
        x.parent = y

# Example usage with 1000 random inputs
rb_tree = RedBlackTree()
random_keys = [random.randint(1, 10000) for _ in range(1000)]
for key in random_keys:
    rb_tree.insert(key, f"value_{key}")

for key in random_keys:
    node = rb_tree.find(key)
    assert node.value == f"value_{key}"

for key in random.sample(random_keys, 500):
    rb_tree.delete(key)

for key in random.sample(random_keys, 500):
    node = rb_tree.find(key)
    assert node is None
