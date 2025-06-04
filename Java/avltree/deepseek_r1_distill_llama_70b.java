public class deepseek_r1_distill_llama_70b {
    private Node root;

    private class Node {
        int key;
        String value;
        Node left;
        Node right;
        int height;

        Node(int key, String value) {
            this.key = key;
            this.value = value;
            this.left = null;
            this.right = null;
            this.height = 1;
        }
    }

    private int getHeight(Node node) {
        if (node == null) return 0;
        return node.height;
    }

    private void updateHeight(Node node) {
        node.height = 1 + Math.max(getHeight(node.left), getHeight(node.right));
    }

    private int getBalance(Node node) {
        if (node == null) return 0;
        return getHeight(node.left) - getHeight(node.right);
    }

    private Node rotateRight(Node node) {
        Node temp = node.left;
        node.left = temp.right;
        temp.right = node;
        updateHeight(node);
        updateHeight(temp);
        return temp;
    }

    private Node rotateLeft(Node node) {
        Node temp = node.right;
        node.right = temp.left;
        temp.left = node;
        updateHeight(node);
        updateHeight(temp);
        return temp;
    }

    private Node rebalance(Node node) {
        int balance = getBalance(node);
        if (balance > 1) {
            if (getBalance(node.left) < 0) {
                node.left = rotateLeft(node.left);
            }
            return rotateRight(node);
        } else if (balance < -1) {
            if (getBalance(node.right) > 0) {
                node.right = rotateRight(node.right);
            }
            return rotateLeft(node);
        }
        return node;
    }

    public void insert(int key, String value) {
        root = insert(root, key, value);
    }

    private Node insert(Node node, int key, String value) {
        if (node == null) return new Node(key, value);
        if (key < node.key) {
            node.left = insert(node.left, key, value);
        } else if (key > node.key) {
            node.right = insert(node.right, key, value);
        } else {
            node.value = value;
            return node;
        }
        updateHeight(node);
        return rebalance(node);
    }

    public void delete(int key) {
        root = delete(root, key);
    }

    private Node delete(Node node, int key) {
        if (node == null) return null;
        if (key < node.key) {
            node.left = delete(node.left, key);
        } else if (key > node.key) {
            node.right = delete(node.right, key);
        } else {
            if (node.left == null && node.right == null) {
                return null;
            } else if (node.left == null) {
                return node.right;
            } else if (node.right == null) {
                return node.left;
            } else {
                Node temp = node.right;
                while (temp.left != null) {
                    temp = temp.left;
                }
                node.key = temp.key;
                node.value = temp.value;
                node.right = delete(node.right, temp.key);
            }
        }
        if (node == null) return null;
        updateHeight(node);
        return rebalance(node);
    }

    public String find(int key) {
        return find(root, key);
    }

    private String find(Node node, int key) {
        if (node == null) return null;
        if (key < node.key) {
            return find(node.left, key);
        } else if (key > node.key) {
            return find(node.right, key);
        } else {
            return node.value;
        }
    }

    public static void main(String[] args) {
        deepseek_r1_distill_llama_70b avlTree = new deepseek_r1_distill_llama_70b();
        java.util.Random rand = new java.util.Random();
        for (int i = 0; i < 1000; i++) {
            int key = rand.nextInt(10000);
            avlTree.insert(key, "Value " + key);
        }
        for (int i = 0; i < 500; i++) {
            int key = rand.nextInt(10000);
            avlTree.delete(key);
        }
        for (int i = 0; i < 1000; i++) {
            int key = rand.nextInt(10000);
            avlTree.find(key);
        }
    }
}