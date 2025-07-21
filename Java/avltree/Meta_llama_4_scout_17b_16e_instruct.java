import java.util.ArrayList;
import java.util.List;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import java.util.Random;

class Node {
    int key;
    Node left;
    Node right;
    int height;

    public Node(int key) {
        this.key = key;
        this.left = null;
        this.right = null;
        this.height = 1;
    }
}

class AVLTree {
    Node root;

    public int getHeight(Node node) {
        if (node == null) {
            return 0;
        }
        return node.height;
    }

    public void updateHeight(Node node) {
        node.height = Math.max(getHeight(node.left), getHeight(node.right)) + 1;
    }

    public int getBalanceFactor(Node node) {
        if (node == null) {
            return 0;
        }
        return getHeight(node.left) - getHeight(node.right);
    }

    public Node rightRotate(Node node) {
        Node temp = node.left;
        node.left = temp.right;
        temp.right = node;

        updateHeight(node);
        updateHeight(temp);

        return temp;
    }

    public Node leftRotate(Node node) {
        Node temp = node.right;
        node.right = temp.left;
        temp.left = node;

        updateHeight(node);
        updateHeight(temp);

        return temp;
    }

    public Node rebalance(Node node) {
        updateHeight(node);

        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1) {
            if (getHeight(node.left.left) >= getHeight(node.left.right)) {
                node = rightRotate(node);
            } else {
                node.left = leftRotate(node.left);
                node = rightRotate(node);
            }
        } else if (balanceFactor < -1) {
            if (getHeight(node.right.right) >= getHeight(node.right.left)) {
                node = leftRotate(node);
            } else {
                node.right = rightRotate(node.right);
                node = leftRotate(node);
            }
        }

        return node;
    }

    public Node insert(Node node, int key) {
        if (node == null) {
            return new Node(key);
        }

        if (key < node.key) {
            node.left = insert(node.left, key);
        } else if (key > node.key) {
            node.right = insert(node.right, key);
        } else {
            return node;
        }

        return rebalance(node);
    }

    public boolean contains(Node node, int key) {
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

    public Node delete(Node node, int key) {
        if (node == null) {
            return node;
        }

        if (key < node.key) {
            node.left = delete(node.left, key);
        } else if (key > node.key) {
            node.right = delete(node.right, key);
        } else {
            if (node.left == null) {
                return node.right;
            } else if (node.right == null) {
                return node.left;
            }

            Node temp = node.right;
            while (temp.left != null) {
                temp = temp.left;
            }
            node.key = temp.key;

            node.right = delete(node.right, temp.key);
        }

        if (node == null) {
            return node;
        }

        return rebalance(node);
    }
}


public class Meta_llama_4_scout_17b_16e_instruct {
    public static void main(String[] args) {
        AVLTree avlTree = new AVLTree();
        List<Integer> keys = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader("../../inputs.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                int key = Integer.parseInt(line.trim());
                keys.add(key);
                avlTree.root = avlTree.insert(avlTree.root, key);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}