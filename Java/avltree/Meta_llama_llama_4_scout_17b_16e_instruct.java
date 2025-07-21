import java.util.ArrayList;
import java.util.List;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import java.util.Random;

public class Meta_llama_llama_4_scout_17b_16e_instruct {

    // Node class representing each node in the AVL tree
    static class Node {
        int key;
        Node left;
        Node right;
        int height;

        public Node(int key) {
            this.key = key;
            this.height = 1;
        }
    }

    // Method to get the height of a node
    private int getHeight(Node node) {
        if (node == null) {
            return 0;
        }
        return node.height;
    }

    // Method to update the height of a node
    private void updateHeight(Node node) {
        node.height = Math.max(getHeight(node.left), getHeight(node.right)) + 1;
    }

    // Method to get the balance factor of a node
    private int getBalanceFactor(Node node) {
        if (node == null) {
            return 0;
        }
        return getHeight(node.left) - getHeight(node.right);
    }

    // Method to perform a right rotation
    private Node rotateRight(Node node) {
        Node temp = node.left;
        node.left = temp.right;
        temp.right = node;

        updateHeight(node);
        updateHeight(temp);

        return temp;
    }

    // Method to perform a left rotation
    private Node rotateLeft(Node node) {
        Node temp = node.right;
        node.right = temp.left;
        temp.left = node;

        updateHeight(node);
        updateHeight(temp);

        return temp;
    }

    // Method to rebalance the tree after insertion or deletion
    private Node rebalance(Node node) {
        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1) {
            if (getHeight(node.left.left) >= getHeight(node.left.right)) {
                node = rotateRight(node);
            } else {
                node.left = rotateLeft(node.left);
                node = rotateRight(node);
            }
        } else if (balanceFactor < -1) {
            if (getHeight(node.right.right) >= getHeight(node.right.left)) {
                node = rotateLeft(node);
            } else {
                node.right = rotateRight(node.right);
                node = rotateLeft(node);
            }
        }

        return node;
    }

    // Method to insert a new key into the AVL tree
    public Node insert(Node node, int key) {
        if (node == null) {
            return new Node(key);
        }

        if (key < node.key) {
            node.left = insert(node.left, key);
        } else if (key > node.key) {
            node.right = insert(node.right, key);
        }

        updateHeight(node);
        return rebalance(node);
    }

    // Method to generate 1000 random keys and insert them into the AVL treepublic static void main(String[] args) {
    public static void main(String[] args) {
        Meta_llama_llama_4_scout_17b_16e_instruct avlTree = new Meta_llama_llama_4_scout_17b_16e_instruct();
        List<Integer> keys = new ArrayList<>();
        Node root = null;

        try (BufferedReader br = new BufferedReader(new FileReader("../../inputs.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                int key = Integer.parseInt(line.trim());
                keys.add(key);
                root = avlTree.insert(root, key);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }


}