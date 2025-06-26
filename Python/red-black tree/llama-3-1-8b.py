class Node:
    def __init__(self, key, value, color, left=None, right=None, parent=None):
        self.key = key
        self.value = value
        self.color = color
        self.left = left
        self.right = right
        self.parent = parent

class RedBlackTree:
    def __init__(self):
        self.NIL = Node(None, None, 'black')
        self.root = self.NIL

    def pre_order(self, node):
        if node != self.NIL:
            self.pre_order(node.left)
            print(f"Key: {node.key}, Value: {node.value}, Color: {node.color}")
            self.pre_order(node.right)

    def post_order(self, node):
        if node != self.NIL:
            self.post_order(node.left)
            self.post_order(node.right)
            print(f"Key: {node.key}, Value: {node.value}, Color: {node.color}")

    def in_order(self, node):
        if node != self.NIL:
            self.in_order(node.left)
            print(f"Key: {node.key}, Value: {node.value}, Color: {node.color}")
            self.in_order(node.right)

    def left_rotate(self, x):
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

    def right_rotate(self, x):
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

    def fix_insert(self, k):
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
                        self.right_rotate(k)
                    k.parent.color = 'black'
                    k.parent.parent.color = 'red'
                    self.left_rotate(k.parent.parent)
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
                        self.left_rotate(k)
                    k.parent.color = 'black'
                    k.parent.parent.color = 'red'
                    self.right_rotate(k.parent.parent)
            if k == self.root:
                break
        self.root.color = 'black'

    def insert(self, key, value):
        node = Node(key, value, 'red')
        node.parent = None
        node.left = self.NIL
        node.right = self.NIL
        node.color = 'red'

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

        self.fix_insert(node)

    def delete(self, key):
        self.delete_node(key, self.root)

    def delete_node(self, key, node):
        z = self.NIL
        while node != self.NIL:
            if node.key == key:
                z = node
                break
            elif key < node.key:
                node = node.left
            else:
                node = node.right
        if z == self.NIL:
            print("Key not found")
            return

        y = z
        y_original_color = y.color
        if z.left == self.NIL:
            x = z.right
            self.rb_transplant(z, z.right)
        elif (z.right == self.NIL):
            x = z.left
            self.rb_transplant(z, z.left)
        else:
            y = self.tree_minimum(z.right)
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

    def tree_minimum(self, node):
        while node.left != self.NIL:
            node = node.left
        return node

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
                    self.left_rotate(x.parent)
                    s = x.parent.right
                if s.left.color == 'black' and s.right.color == 'black':
                    s.color = 'red'
                    x = x.parent
                else:
                    if s.right.color == 'black':
                        s.left.color = 'black'
                        s.color = 'red'
                        self.right_rotate(s)
                        s = x.parent.right
                    s.color = x.parent.color
                    x.parent.color = 'black'
                    s.right.color = 'black'
                    self.left_rotate(x.parent)
                    x = self.root
            else:
                s = x.parent.left
                if s.color == 'red':
                    s.color = 'black'
                    x.parent.color = 'red'
                    self.right_rotate(x.parent)
                    s = x.parent.left
                if s.right.color == 'black' and s.right.color == 'black':
                    s.color = 'red'
                    x = x.parent
                else:
                    if s.left.color == 'black':
                        s.right.color = 'black'
                        s.color = 'red'
                        self.left_rotate(s)
                        s = x.parent.left
                    s.color = x.parent.color
                    x.parent.color = 'black'
                    s.left.color = 'black'
                    self.right_rotate(x.parent)
                    x = self.root
        x.color = 'black'

    def pre_order_traversal(self):
        self.pre_order(self.root)

    def post_order_traversal(self):
        self.post_order(self.root)

    def in_order_traversal(self):
        self.in_order(self.root)

# Test the implementation
rb_tree = RedBlackTree()
rb_tree.insert(10, 'A')
rb_tree.insert(20, 'B')
rb_tree.insert(5, 'C')
rb_tree.insert(15, 'D')
rb_tree.insert(25, 'E')
rb_tree.insert(3, 'F')
rb_tree.insert(7, 'G')
rb_tree.insert(12, 'H')
rb_tree.insert(18, 'I')
rb_tree.insert(22, 'J')
rb_tree.insert(30, 'K')

print("Pre-order traversal:")
rb_tree.pre_order_traversal()

print("\nPost-order traversal:")
rb_tree.post_order_traversal()

print("\nIn-order traversal:")
rb_tree.in_order_traversal()

rb_tree.delete(20)
print("\nAfter deleting 20:")
rb_tree.in_order_traversal()
