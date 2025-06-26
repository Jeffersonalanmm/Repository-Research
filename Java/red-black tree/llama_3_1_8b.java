package Java.red-black tree;

enum Color {
    RED,
    BLACK
}

// Define the Node class
class Node {
    int key;
    Color color;
    Node left;
    Node right;
    Node parent;

    public Node(int key) {
        this.key = key;
        this.color = Color.RED;
        this.left = null;
        this.right = null;
        this.parent = null;
    }
}
public class llama_3_1_8b {
    private Node root;

    // Insert a new node into the tree
    public void insert(int key) {
        Node node = new Node(key);
        if (root == null) {
            root = node;
            root.color = Color.BLACK;
        } else {
            insertNode(root, node);
        }
        balanceTree(root);
    }

    // Helper function to insert a new node into the tree
    private void insertNode(Node current, Node node) {
        if (node.key < current.key) {
            if (current.left == null) {
                current.left = node;
                node.parent = current;
            } else {
                insertNode(current.left, node);
            }
        } else {
            if (current.right == null) {
                current.right = node;
                node.parent = current;
            } else {
                insertNode(current.right, node);
            }
        }
    }

    // Balance the tree after insertion
    private void balanceTree(Node current) {
        while (current.parent != null && current.parent.color == Color.RED) {
            Node grandparent = current.parent.parent;
            if (current.parent == grandparent.left) {
                Node uncle = grandparent.right;
                if (uncle != null && uncle.color == Color.RED) {
                    current.parent.color = Color.BLACK;
                    uncle.color = Color.BLACK;
                    grandparent.color = Color.RED;
                    current = grandparent;
                } else {
                    if (current == current.parent.right) {
                        current = current.parent;
                        rotateLeft(current);
                    }
                    current.parent.color = Color.BLACK;
                    grandparent.color = Color.RED;
                    rotateRight(grandparent);
                }
            } else {
                Node uncle = grandparent.left;
                if (uncle != null && uncle.color == Color.RED) {
                    current.parent.color = Color.BLACK;
                    uncle.color = Color.BLACK;
                    grandparent.color = Color.RED;
                    current = grandparent;
                } else {
                    if (current == current.parent.left) {
                        current = current.parent;
                        rotateRight(current);
                    }
                    current.parent.color = Color.BLACK;
                    grandparent.color = Color.RED;
                    rotateLeft(grandparent);
                }
            }
        }
        root.color = Color.BLACK;
    }

    // Rotate left
    private void rotateLeft(Node node) {
        Node newRoot = node.right;
        node.right = newRoot.left;
        if (newRoot.left != null) {
            newRoot.left.parent = node;
        }
        newRoot.parent = node.parent;
        if (node.parent == null) {
            root = newRoot;
        } else if (node == node.parent.left) {
            node.parent.left = newRoot;
        } else {
            node.parent.right = newRoot;
        }
        newRoot.left = node;
        node.parent = newRoot;
    }

    // Rotate right
    private void rotateRight(Node node) {
        Node newRoot = node.left;
        node.left = newRoot.right;
        if (newRoot.right != null) {
            newRoot.right.parent = node;
        }
        newRoot.parent = node.parent;
        if (node.parent == null) {
            root = newRoot;
        } else if (node == node.parent.right) {
            node.parent.right = newRoot;
        } else {
            node.parent.left = newRoot;
        }
        newRoot.right = node;
        node.parent = newRoot;
    }

    // Get the height of the tree
    public int getHeight() {
        return getHeight(root);
    }

    // Helper function to get the height of the tree
    private int getHeight(Node node) {
        if (node == null) {
            return 0;
        }
        return 1 + Math.max(getHeight(node.left), getHeight(node.right));
    }

    // Get the minimum key in the tree
    public int getMinKey() {
        return getMinKey(root).key;
    }

    // Helper function to get the minimum key in the tree
    private Node getMinKey(Node node) {
        while (node.left != null) {
            node = node.left;
        }
        return node;
    }

    // Get the maximum key in the tree
    public int getMaxKey() {
        return getMaxKey(root).key;
    }

    // Helper function to get the maximum key in the tree
    private Node getMaxKey(Node node) {
        while (node.right != null) {
            node = node.right;
        }
        return node;
    }

    // Check if the tree is empty
    public boolean isEmpty() {
        return root == null;
    }

    // Check if the tree contains a key
    public boolean contains(int key) {
        return contains(root, key);
    }

    // Helper function to check if the tree contains a key
    private boolean contains(Node node, int key) {
        if (node == null) {
            return false;
        }
        if (key < node.key) {
            return contains(node.left, key);
        } else if (key > node.key) {
            return contains(node.right, key);
        } else {
            return true;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        RedBlackTree tree = new RedBlackTree();
        for (int i = 0; i < 1000; i++) {
            tree.insert(i);
        }
        System.out.println(tree.getHeight());
        System.out.println(tree.getMinKey());
        System.out.println(tree.getMaxKey());
        System.out.println(tree.isEmpty());
        System.out.println(tree.contains(500));
    }
}
