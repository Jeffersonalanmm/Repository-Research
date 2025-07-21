import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Llama_3_3_70b_versatile {
    // Node class representing each node in the AVL tree
    static class Node {
        int key;
        Node left;
        Node right;
        int height;

        Node(int key) {
            this.key = key;
            this.left = null;
            this.right = null;
            this.height = 1;
        }
    }

    // Method to get the height of a node
    static int getHeight(Node node) {
        if (node == null) {
            return 0;
        }
        return node.height;
    }

    // Method to update the height of a node
    static void updateHeight(Node node) {
        if (node == null) {
            return;
        }
        node.height = Math.max(getHeight(node.left), getHeight(node.right)) + 1;
    }

    // Method to get the balance factor of a node
    static int getBalanceFactor(Node node) {
        if (node == null) {
            return 0;
        }
        return getHeight(node.left) - getHeight(node.right);
    }

    // Method to perform a left rotation
    static Node leftRotate(Node node) {
        Node temp = node.right;
        node.right = temp.left;
        temp.left = node;
        updateHeight(node);
        updateHeight(temp);
        return temp;
    }

    // Method to perform a right rotation
    static Node rightRotate(Node node) {
        Node temp = node.left;
        node.left = temp.right;
        temp.right = node;
        updateHeight(node);
        updateHeight(temp);
        return temp;
    }

    // Method to rebalance the tree after insertion or deletion
    static Node rebalance(Node node) {
        updateHeight(node);
        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor > 1) {
            if (getBalanceFactor(node.left) < 0) {
                node.left = leftRotate(node.left);
            }
            node = rightRotate(node);
        } else if (balanceFactor < -1) {
            if (getBalanceFactor(node.right) > 0) {
                node.right = rightRotate(node.right);
            }
            node = leftRotate(node);
        }
        return node;
    }

    // Method to insert a new key into the AVL tree
    static Node insert(Node node, int key) {
        if (node == null) {
            return new Node(key);
        }
        if (key < node.key) {
            node.left = insert(node.left, key);
        } else if (key > node.key) {
            node.right = insert(node.right, key);
        }
        return rebalance(node);
    }

    // Method to delete a key from the AVL tree
    static Node delete(Node node, int key) {
        if (node == null) {
            return null;
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
        return rebalance(node);
    }

        public static void main(String[] args) {
        Node root = null;
        List<Integer> keys = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader("../../inputs.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                int key = Integer.parseInt(line.trim());
                keys.add(key);
                root = insert(root, key);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}