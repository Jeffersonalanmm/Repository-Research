package Java.red-black tree;
import java.util.Random;

class Node {
    int data;
    Node left;
    Node right;
    Node parent;
    boolean isRed;

    public Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
        this.parent = null;
        this.isRed = true; // New nodes are always red
    }
}
public class llama3_3_70b {
 
    Node root;
    Node nullNode;

    public llama3_3_70b() {
        nullNode = new Node(0);
        nullNode.isRed = false;
        nullNode.left = null;
        nullNode.right = null;
        root = nullNode;
    }

    // Pre-order helper function
    private void preOrderHelper(Node node) {
        if (node != nullNode) {
            // Perform operation on node
            // For example, you can add the node's data to a list
            preOrderHelper(node.left);
            preOrderHelper(node.right);
        }
    }

    // In-order helper function
    private void inOrderHelper(Node node) {
        if (node != nullNode) {
            inOrderHelper(node.left);
            // Perform operation on node
            // For example, you can add the node's data to a list
            inOrderHelper(node.right);
        }
    }

    // Post-order helper function
    private void postOrderHelper(Node node) {
        if (node != nullNode) {
            postOrderHelper(node.left);
            postOrderHelper(node.right);
            // Perform operation on node
            // For example, you can add the node's data to a list
        }
    }

    // Left rotation function
    private void leftRotate(Node x) {
        Node y = x.right;
        x.right = y.left;
        if (y.left != nullNode) {
            y.left.parent = x;
        }
        y.parent = x.parent;
        if (x.parent == null) {
            root = y;
        } else if (x == x.parent.left) {
            x.parent.left = y;
        } else {
            x.parent.right = y;
        }
        y.left = x;
        x.parent = y;
    }

    // Right rotation function
    private void rightRotate(Node x) {
        Node y = x.left;
        x.left = y.right;
        if (y.right != nullNode) {
            y.right.parent = x;
        }
        y.parent = x.parent;
        if (x.parent == null) {
            root = y;
        } else if (x == x.parent.right) {
            x.parent.right = y;
        } else {
            x.parent.left = y;
        }
        y.right = x;
        x.parent = y;
    }

    // Insert function
    public void insert(int data) {
        Node node = new Node(data);
        node.parent = null;
        node.left = nullNode;
        node.right = nullNode;

        Node y = null;
        Node x = root;

        while (x != nullNode) {
            y = x;
            if (node.data < x.data) {
                x = x.left;
            } else {
                x = x.right;
            }
        }

        node.parent = y;
        if (y == null) {
            root = node;
        } else if (node.data < y.data) {
            y.left = node;
        } else {
            y.right = node;
        }

        if (node.parent == null) {
            node.isRed = false;
            return;
        }

        if (node.parent.parent == null) {
            return;
        }

        fixInsert(node);
    }

    // Fix insert function
    private void fixInsert(Node k) {
        Node u;
        while (k.parent.isRed) {
            if (k.parent == k.parent.parent.right) {
                u = k.parent.parent.left;
                if (u.isRed) {
                    u.isRed = false;
                    k.parent.isRed = false;
                    k.parent.parent.isRed = true;
                    k = k.parent.parent;
                } else {
                    if (k == k.parent.left) {
                        k = k.parent;
                        rightRotate(k);
                    }
                    k.parent.isRed = false;
                    k.parent.parent.isRed = true;
                    leftRotate(k.parent.parent);
                }
            } else {
                u = k.parent.parent.right;

                if (u.isRed) {
                    u.isRed = false;
                    k.parent.isRed = false;
                    k.parent.parent.isRed = true;
                    k = k.parent.parent;
                } else {
                    if (k == k.parent.right) {
                        k = k.parent;
                        leftRotate(k);
                    }
                    k.parent.isRed = false;
                    k.parent.parent.isRed = true;
                    rightRotate(k.parent.parent);
                }
            }
            if (k == root) {
                break;
            }
        }
        root.isRed = false;
    }

    // Generate 1000 random inputs and insert them into the Red-Black Tree
    public void generateAndInsertRandomInputs() {
        Random random = new Random();
        for (int i = 0; i < 1000; i++) {
            int randomData = random.nextInt(1001);
            insert(randomData);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        RedBlackTree tree = new RedBlackTree();
        tree.generateAndInsertRandomInputs();
    }
}
