package Java.red-black tree;
import java.util.Random;
public class deepseek_r1_disill_llama<T extends Comparable<T>> {

    private enum Color {
        RED, BLACK
    }

    private static class Node<T> {
        T value;
        Color color;
        Node<T> left;
        Node<T> right;
        Node<T> parent;

        Node(T value) {
            this.value = value;
            this.color = Color.RED;
            this.left = null;
            this.right = null;
            this.parent = null;
        }
    }

    private Node<T> root;

    public RedBlackTree() {
        this.root = null;
    }

    // Helper method to get the grandparent of a node
    private Node<T> getGrandparent(Node<T> node) {
        if (node.parent != null) {
            return node.parent.parent;
        }
        return null;
    }

    // Helper method to get the sibling of a node
    private Node<T> getSibling(Node<T> node) {
        if (node.parent == null) {
            return null;
        }
        if (node.parent.left == node) {
            return node.parent.right;
        } else {
            return node.parent.left;
        }
    }

    // Helper method to get the uncle of a node
    private Node<T> getUncle(Node<T> node) {
        Node<T> parent = node.parent;
        Node<T> grandparent = getGrandparent(node);
        if (grandparent == null) {
            return null;
        }
        if (parent == grandparent.left) {
            return grandparent.right;
        } else {
            return grandparent.left;
        }
    }

    // Rotate left
    private void rotateLeft(Node<T> node) {
        Node<T> temp = node.right;
        node.right = temp.left;
        if (temp.left != null) {
            temp.left.parent = node;
        }
        temp.parent = node.parent;
        if (node.parent == null) {
            root = temp;
        } else if (node == node.parent.left) {
            node.parent.left = temp;
        } else {
            node.parent.right = temp;
        }
        temp.left = node;
        node.parent = temp;
    }

    // Rotate right
    private void rotateRight(Node<T> node) {
        Node<T> temp = node.left;
        node.left = temp.right;
        if (temp.right != null) {
            temp.right.parent = node;
        }
        temp.parent = node.parent;
        if (node.parent == null) {
            root = temp;
        } else if (node == node.parent.right) {
            node.parent.right = temp;
        } else {
            node.parent.left = temp;
        }
        temp.right = node;
        node.parent = temp;
    }

    // Fix the tree after insertion
    private void fixInsert(Node<T> node) {
        while (node.parent != null && node.parent.color == Color.RED) {
            Node<T> uncle = getUncle(node);
            Node<T> grandparent = getGrandparent(node);

            if (uncle != null && uncle.color == Color.RED) {
                node.parent.color = Color.BLACK;
                uncle.color = Color.BLACK;
                grandparent.color = Color.RED;
                node = grandparent;
            } else {
                if (node.parent == grandparent.right) {
                    rotateLeft(grandparent);
                    Node<T> temp = node.parent;
                    node.parent = grandparent;
                    temp.color = Color.BLACK;
                    grandparent.color = Color.RED;
                } else {
                    rotateRight(grandparent);
                    Node<T> temp = node.parent;
                    node.parent = grandparent;
                    temp.color = Color.BLACK;
                    grandparent.color = Color.RED;
                }
                node = grandparent;
            }
        }
        root.color = Color.BLACK;
    }

    // Insert a new node
    public void insert(T value) {
        Node<T> newNode = new Node<>(value);
        if (root == null) {
            root = newNode;
            return;
        }

        Node<T> current = root;
        while (true) {
            if (value.compareTo(current.value) < 0) {
                if (current.left == null) {
                    current.left = newNode;
                    newNode.parent = current;
                    break;
                }
                current = current.left;
            } else {
                if (current.right == null) {
                    current.right = newNode;
                    newNode.parent = current;
                    break;
                }
                current = current.right;
            }
        }
        fixInsert(newNode);
    }

    // Fix the tree after deletion
    private void fixDelete(Node<T> node) {
        while (node != null && node != root && node.color == Color.BLACK) {
            if (node == node.parent.left) {
                Node<T> sibling = node.parent.right;
                if (sibling.color == Color.RED) {
                    sibling.color = Color.BLACK;
                    node.parent.color = Color.RED;
                    rotateLeft(node.parent);
                    sibling = node.parent.right;
                }
                if (sibling.left.color == Color.BLACK && sibling.right.color == Color.BLACK) {
                    sibling.color = Color.RED;
                    node = node.parent;
                } else {
                    if (sibling.right.color == Color.BLACK) {
                        sibling.left.color = Color.BLACK;
                        sibling.color = Color.RED;
                        rotateRight(sibling);
                        sibling = node.parent.right;
                    }
                    sibling.color = node.parent.color;
                    node.parent.color = Color.BLACK;
                    sibling.right.color = Color.BLACK;
                    rotateLeft(node.parent);
                    node = root;
                }
            } else {
                Node<T> sibling = node.parent.left;
                if (sibling.color == Color.RED) {
                    sibling.color = Color.BLACK;
                    node.parent.color = Color.RED;
                    rotateRight(node.parent);
                    sibling = node.parent.left;
                }
                if (sibling.left.color == Color.BLACK && sibling.right.color == Color.BLACK) {
                    sibling.color = Color.RED;
                    node = node.parent;
                } else {
                    if (sibling.left.color == Color.BLACK) {
                        sibling.right.color = Color.BLACK;
                        sibling.color = Color.RED;
                        rotateLeft(sibling);
                        sibling = node.parent.left;
                    }
                    sibling.color = node.parent.color;
                    node.parent.color = Color.BLACK;
                    sibling.left.color = Color.BLACK;
                    rotateRight(node.parent);
                    node = root;
                }
            }
        }
        if (node != null) {
            node.color = Color.BLACK;
        }
    }

    // Delete a node
    public void delete(T value) {
        Node<T> node = findNode(value);
        if (node == null) {
            return;
        }

        Node<T> replacement;
        if (node.left == null && node.right == null) {
            replacement = null;
        } else if (node.left == null) {
            replacement = node.right;
        } else if (node.right == null) {
            replacement = node.left;
        } else {
            replacement = findMin(node.right);
            if (replacement.parent == node) {
                replacement.right = node.right;
                if (replacement.right != null) {
                    replacement.right.parent = replacement;
                }
            } else {
                if (replacement.left != null) {
                    replacement.left.parent = replacement.parent;
                }
                replacement.parent.left = replacement.left;
                replacement.left = node.left;
                if (replacement.left != null) {
                    replacement.left.parent = replacement;
                }
                replacement.right = node.right;
                if (replacement.right != null) {
                    replacement.right.parent = replacement;
                }
            }
        }

        if (replacement != null) {
            replacement.parent = node.parent;
            if (node.parent == null) {
                root = replacement;
            } else if (node == node.parent.left) {
                node.parent.left = replacement;
            } else {
                node.parent.right = replacement;
            }
        } else {
            if (node.parent != null) {
                if (node == node.parent.left) {
                    node.parent.left = null;
                } else {
                    node.parent.right = null;
                }
            } else {
                root = null;
            }
        }

        if (node.color == Color.BLACK) {
            fixDelete(replacement);
        }
    }

    // Find the minimum node in a subtree
    private Node<T> findMin(Node<T> node) {
        while (node.left != null) {
            node = node.left;
        }
        return node;
    }

    // Find a node with a given value
    private Node<T> findNode(T value) {
        Node<T> current = root;
        while (current != null) {
            if (value.compareTo(current.value) < 0) {
                current = current.left;
            } else if (value.compareTo(current.value) > 0) {
                current = current.right;
            } else {
                return current;
            }
        }
        return null;
    }

    // In-order traversal
    public void inOrderTraversal() {
        inOrderHelper(root);
    }

    private void inOrderHelper(Node<T> node) {
        if (node != null) {
            inOrderHelper(node.left);
            System.out.print(node.value + " ");
            inOrderHelper(node.right);
        }
    }

    // Pre-order traversal
    public void preOrderTraversal() {
        preOrderHelper(root);
    }

    private void preOrderHelper(Node<T> node) {
        if (node != null) {
            System.out.print(node.value + " ");
            preOrderHelper(node.left);
            preOrderHelper(node.right);
        }
    }

    // Post-order traversal
    public void postOrderTraversal() {
        postOrderHelper(root);
    }

    private void postOrderHelper(Node<T> node) {
        if (node != null) {
            postOrderHelper(node.left);
            postOrderHelper(node.right);
            System.out.print(node.value + " ");
        }
    }

    public static void main(String[] args) {
        RedBlackTree<Integer> rbt = new RedBlackTree<>();
        Random random = new Random();
        
        // Insert 1000 random integers
        for (int i = 0; i < 1000; i++) {
            rbt.insert(random.nextInt(10000));
        }
        
        // Delete some values
        rbt.delete(5000);
        rbt.delete(2500);
        rbt.delete(7500);
        
        // Perform in-order traversal
        rbt.inOrderTraversal();
    }
}
