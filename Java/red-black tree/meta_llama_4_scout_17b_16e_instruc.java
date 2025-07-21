import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Random;
class Node {
    int key;
    Node left;
    Node right;
    Node parent;
    boolean isBlack;

    public Node(int key) {
        this.key = key;
        this.left = null;
        this.right = null;
        this.parent = null;
        this.isBlack = false;
    }
}

public class meta_llama_4_scout_17b_16e_instruc {

    Node root;
    Node TNULL;

    public meta_llama_4_scout_17b_16e_instruc() {
        TNULL = new Node(0);
        TNULL.isBlack = true;
        TNULL.left = null;
        TNULL.right = null;
        root = TNULL;
    }

    void preOrderHelper(Node node) {
        if (node != TNULL) {
            // Perform operation
            node = node.left;
            preOrderHelper(node);
            node = node.parent;
            node = node.right;
            preOrderHelper(node);
        }
    }

    void inOrderHelper(Node node) {
        if (node != TNULL) {
            inOrderHelper(node.left);
            // Perform operation
            inOrderHelper(node.right);
        }
    }

    void postOrderHelper(Node node) {
        if (node != TNULL) {
            postOrderHelper(node.left);
            postOrderHelper(node.right);
            // Perform operation
        }
    }

    void leftRotate(Node x) {
        Node y = x.right;
        x.right = y.left;
        if (y.left != TNULL) {
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

    void rightRotate(Node y) {
        Node x = y.left;
        y.left = x.right;
        if (x.right != TNULL) {
            x.right.parent = y;
        }

        x.parent = y.parent;
        if (y.parent == null) {
            root = x;
        } else if (y == y.parent.right) {
            y.parent.right = x;
        } else {
            y.parent.left = x;
        }
        x.right = y;
        y.parent = x;
    }

    void insertFix(Node k) {
        Node u;
        while (k.parent.isBlack == false) {
            if (k.parent == k.parent.parent.right) {
                u = k.parent.parent.left;
                if (u.isBlack == false) {
                    u.isBlack = true;
                    k.parent.isBlack = true;
                    k.parent.parent.isBlack = false;
                    k = k.parent.parent;
                } else {
                    if (k == k.parent.left) {
                        k = k.parent;
                        rightRotate(k);
                    }
                    k.parent.isBlack = true;
                    k.parent.parent.isBlack = false;
                    leftRotate(k.parent.parent);
                }
            } else {
                u = k.parent.parent.right;

                if (u.isBlack == false) {
                    u.isBlack = true;
                    k.parent.isBlack = true;
                    k.parent.parent.isBlack = false;
                    k = k.parent.parent;
                } else {
                    if (k == k.parent.right) {
                        k = k.parent;
                        leftRotate(k);
                    }
                    k.parent.isBlack = true;
                    k.parent.parent.isBlack = false;
                    rightRotate(k.parent.parent);
                }
            }
            if (k == root) {
                break;
            }
        }
        root.isBlack = true;
    }

    void insertNode(int key) {
        Node node = new Node(key);
        node.parent = null;
        node.left = TNULL;
        node.right = TNULL;
        node.isBlack = false;

        Node y = null;
        Node x = root;

        while (x != TNULL) {
            y = x;
            if (node.key < x.key) {
                x = x.left;
            } else {
                x = x.right;
            }
        }

        node.parent = y;
        if (y == null) {
            root = node;
        } else if (node.key < y.key) {
            y.left = node;
        } else {
            y.right = node;
        }

        if (node.parent == null) {
            node.isBlack = true;
            return;
        }

        if (node.parent.parent == null) {
            return;
        }

        insertFix(node);
    }


    public static void main(String[] args) {
        meta_llama_4_scout_17b_16e_instruc rbt = new meta_llama_4_scout_17b_16e_instruc();

        try (BufferedReader br = new BufferedReader(new FileReader("../../inputs.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                int value = Integer.parseInt(line.trim());
                rbt.insertNode(value);
            }
        } catch (java.io.IOException e) {
            return;
        }

    }
}

