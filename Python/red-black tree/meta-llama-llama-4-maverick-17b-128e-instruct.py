import random

class Node:
    def __init__(self, key, color, left=None, right=None, parent=None):
        self.key = key
        self.color = color
        self.left = left
        self.right = right
        self.parent = parent

class RedBlackTree:
    def __init__(self):
        self.NIL = Node(None, 'black')
        self.root = self.NIL

    def pre_order(self, node):
        if node != self.NIL:
            self.pre_order(node.left)
            self.pre_order(node.right)

    def in_order(self, node):
        if node != self.NIL:
            self.in_order(node.left)
            # node.key can be used here for verification
            self.in_order(node.right)

    def post_order(self, node):
        if node != self.NIL:
            self.post_order(node.left)
            self.post_order(node.right)

    def search(self, key):
        current = self.root
        while current != self.NIL:
            if current.key == key:
                return current
            elif current.key < key:
                current = current.right
            else:
                current = current.left
        return None

    def minimum(self, node):
        while node.left != self.NIL:
            node = node.left
        return node

    def maximum(self, node):
        while node.right != self.NIL:
            node = node.right
        return node

    def successor(self, node):
        if node.right != self.NIL:
            return self.minimum(node.right)
        y = node.parent
        while y != self.NIL and node == y.right:
            node = y
            y = y.parent
        return y

    def predecessor(self, node):
        if node.left != self.NIL:
            return self.maximum(node.left)
        y = node.parent
        while y != self.NIL and node == y.left:
            node = y
            y = y.parent
        return y

    def rotate_left(self, x):
        y = x.right
        x.right = y.left
        if y.left != self.NIL:
            y.left.parent = x
        y.parent = x.parent
        if x.parent == None:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def rotate_right(self, x):
        y = x.left
        x.left = y.right
        if y.right != self.NIL:
            y.right.parent = x
        y.parent = x.parent
        if x.parent == None:
            self.root = y
        elif x == x.parent.right:
            x.parent.right = y
        else:
            x.parent.left = y
        y.right = x
        x.parent = y

    def insert_fix(self, k):
        while k.parent.color == 'red':
            if k.parent == k.parent.parent.right:
                u = k.parent.parent.left
                if u.color == 'red':
                    u.color = 'black'
                    k.parent.color = 'black'
                    k.parent.parent.color = 'red'
                    k = k.parent.parent
                else:
                    if k == k.parent.left:
                        k = k.parent
                        self.rotate_right(k)
                    k.parent.color = 'black'
                    k.parent.parent.color = 'red'
                    self.rotate_left(k.parent.parent)
            else:
                u = k.parent.parent.right

                if u.color == 'red':
                    u.color = 'black'
                    k.parent.color = 'black'
                    k.parent.parent.color = 'red'
                    k = k.parent.parent
                else:
                    if k == k.parent.right:
                        k = k.parent
                        self.rotate_left(k)
                    k.parent.color = 'black'
                    k.parent.parent.color = 'red'
                    self.rotate_right(k.parent.parent)
            if k == self.root:
                break
        self.root.color = 'black'

    def insert(self, key):
        node = Node(key, 'red')
        node.parent = None
        node.left = self.NIL
        node.right = self.NIL

        y = None
        x = self.root

        while x != self.NIL:
            y = x
            if node.key < x.key:
                x = x.left
            else:
                x = x.right

        node.parent = y
        if y == None:
            self.root = node
        elif node.key < y.key:
            y.left = node
        else:
            y.right = node

        if node.parent == None:
            node.color = 'black'
            return

        if node.parent.parent == None:
            return

        self.insert_fix(node)

    def rb_transplant(self, u, v):
        if u.parent == None:
            self.root = v
        elif u == u.parent.left:
            u.parent.left = v
        else:
            u.parent.right = v
        v.parent = u.parent

    def delete_fix(self, x):
        while x != self.root and x.color == 'black':
            if x == x.parent.left:
                s = x.parent.right
                if s.color == 'red':
                    s.color = 'black'
                    x.parent.color = 'red'
                    self.rotate_left(x.parent)
                    s = x.parent.right

                if s.left.color == 'black' and s.right.color == 'black':
                    s.color = 'red'
                    x = x.parent
                else:
                    if s.right.color == 'black':
                        s.left.color = 'black'
                        s.color = 'red'
                        self.rotate_right(s)
                        s = x.parent.right

                    s.color = x.parent.color
                    x.parent.color = 'black'
                    s.right.color = 'black'
                    self.rotate_left(x.parent)
                    x = self.root
            else:
                s = x.parent.left
                if s.color == 'red':
                    s.color = 'black'
                    x.parent.color = 'red'
                    self.rotate_right(x.parent)
                    s = x.parent.left

                if s.right.color == 'black' and s.right.color == 'black':
                    s.color = 'red'
                    x = x.parent
                else:
                    if s.left.color == 'black':
                        s.right.color = 'black'
                        s.color = 'red'
                        self.rotate_left(s)
                        s = x.parent.left

                    s.color = x.parent.color
                    x.parent.color = 'black'
                    s.left.color = 'black'
                    self.rotate_right(x.parent)
                    x = self.root
        x.color = 'black'

    def delete(self, key):
        z = self.search(key)
        if z == None:
            return
        y = z
        y_original_color = y.color
        if z.left == self.NIL:
            x = z.right
            self.rb_transplant(z, z.right)
        elif z.right == self.NIL:
            x = z.left
            self.rb_transplant(z, z.left)
        else:
            y = self.minimum(z.right)
            y_original_color = y.color
            x = y.right
            if y.parent == z:
                x.parent = y
            else:
                self.rb_transplant(y, y.right)
                y.right = z.right
                y.right.parent = y

            self.rb_transplant(z, y)
            y.left = z.left
            y.left.parent = y
            y.color = z.color
        if y_original_color == 'black':
            self.delete_fix(x)

def test_rb_tree():
    rb_tree = RedBlackTree()
    keys = [random.randint(1, 1000) for _ in range(1000)]
    for key in keys:
        rb_tree.insert(key)

    for key in keys:
        rb_tree.delete(key)

test_rb_tree()