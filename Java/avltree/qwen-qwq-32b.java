
public Node rightRotate(Node y) {
    Node x = y.left;
    Node T2 = x.right;

    x.right = y;
    y.left = T2;

    updateHeight(y);
    updateHeight(x);

    return x; // new root
}

public Node leftRotate(Node x) {
    Node y = x.right;
    Node T2 = y.left;

    y.left = x;
    x.right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}


public Node insert(Node node, int key) {
    if (node == null)
        return new Node(key);

    if (key < node.key)
        node.left = insert(node.left, key);
    else if (key > node.key)
        node.right = insert(node.right, key);
    else
        return node; // duplicate, do nothing

    // Update height
    node.height = 1 + Math.max(height(node.left), height(node.right));

    // Get balance factor
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node.left.key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node.right.key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node.left.key) {
        node.left = leftRotate(node.left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node.right.key) {
        node.right = rightRotate(node.right);
        return leftRotate(node);
    }

    return node;
}

public Node deleteNode(Node root, int key) {
    if (root == null)
        return root;

    if (key < root.key)
        root.left = deleteNode(root.left, key);
    else if (key > root.key)
        root.right = deleteNode(root.right, key);
    else {
        // Node with only one child or no child
        if (root.left == null || root.right == null) {
            Node temp = null;
            if (temp == root.left)
                temp = root.right;
            else
                temp = root.left;

            // Case 1: no child
            if (temp == null) {
                temp = root;
                root = null;
            } else // Case 2: one child
                root = temp; // Copy the contents of the non-null child
            // But in Java, since we can't directly copy, perhaps better to just replace the node with the child.
            // Alternatively, handle the cases where the node has one or two children.

            // Wait, perhaps better to handle the two children case first.

            // Case 3: two children: get the in-order successor (smallest in right subtree)
            Node temp = minValueNode(root.right);
            root.key = temp.key;
            root.right = deleteNode(root.right, temp.key);
        }
    }

    // If the tree had only one node, return it
    if (root == null)
        return root;

    // Update height
    root.height = 1 + Math.max(height(root.left), height(root.right));

    // Get balance factor
    int balance = getBalance(root);

    // Now, four cases for rebalancing

    // Left Left
    if (balance > 1 && getBalance(root.left) >= 0)
        return rightRotate(root);

    // Left Right
    if (balance > 1 && getBalance(root.left) < 0) {
        root.left = leftRotate(root.left);
        return rightRotate(root);
    }

    // Right Right
    if (balance < -1 && getBalance(root.right) <= 0)
        return leftRotate(root);

    // Right Left
    if (balance < -1 && getBalance(root.right) > 0) {
        root.right = rightRotate(root.right);
        return leftRotate(root);
    }

    return root;
}



private int height(Node N) {
    return (N == null) ? -1 : N.height;
}

private int getBalance(Node N) {
    if (N == null)
        return 0;
    return height(N.left) - height(N.right);
}

private static class Node {
    int key;
    Node left, right;
    int height;

    Node(int key) {
        this.key = key;
        height = 1;
    }
}

private Node minValueNode(Node node) {
    Node current = node;
    while (current.left != null)
        current = current.left;
    return current;
}

public class AVLTree {
    private static class Node {
        int key;
        Node left, right;
        int height;

        Node(int key) {
            this.key = key;
            height = 1;
        }
    }

    Node root;

    // Insert and delete methods here.

    public Node insert(Node node, int key) {
        // ... as above
    }

    public Node deleteNode(Node root, int key) {
        // ... as above
    }

    private Node rightRotate(Node y) {
        Node x = y.left;
        Node T2 = x.right;

        x.right = y;
        y.left = T2;

        y.height = Math.max(height(y.left), height(y.right)) +1;
        x.height = Math.max(height(x.left), height(x.right)) +1;

        return x;
    }

public Node rightRotate(Node y) {
    Node x = y.left;
    Node T2 = x.right;

    x.right = y;
    y.left = T2;

    // Update heights
    y.height = 1 + Math.max(height(y.left), height(y.right));
    x.height = 1 + Math.max(height(x.left), height(x.right));

    return x;
}

public Node rightRotate(Node y) {
    Node x = y.left;
    Node T2 = x.right;

    // Perform rotation
    x.right = y;
    y.left = T2;

    // Update heights
    y.height = 1 + Math.max(height(y.left), height(y.right));
    x.height = 1 + Math.max(height(x.left), height(x.right));

    return x;
}

public class AVLTree {
    private static class Node {
        // as before
    }

    Node root;

    // insert, delete, rotations, etc.

    public static void main(String[] args) {
        AVLTree tree = new AVLTree();
        Random rand = new Random();
        for (int i = 0; i < 1000; i++) {
            int key = rand.nextInt(10000);
            tree.root = tree.insert(tree.root, key);
        }
        // maybe some checks, but no prints.
    }
}

public Node insert(Node node, int key) {
    if (node == null)
        return new Node(key);

    if (key < node.key)
        node.left = insert(node.left, key);
    else if (key > node.key)
        node.right = insert(node.right, key);
    else // duplicate, do nothing
        return node;

    // Update height
    node.height = 1 + Math.max(height(node.left), height(node.right));

    // Get balance factor
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node.left.key)
        return rightRotate(node);

    // Left Right Case
    if (balance > 1 && key > node.left.key) {
        node.left = leftRotate(node.left);
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node.right.key)
        return leftRotate(node);

    // Right Left Case
    if (balance < -1 && key < node.right.key) {
        node.right = rightRotate(node.right);
        return leftRotate(node);
    }

    return node;
}

if (balance > 1) {
    if (getBalance(root.left) >= 0) {
        return rightRotate(root);
    } else {
        root.left = leftRotate(root.left);
        return rightRotate(root);
    }
} else if (balance < -1) {
    if (getBalance(root.right) <=0 ) {
        return leftRotate(root);
    } else {
        root.right = rightRotate(root.right);
        return leftRotate(root);
    }
}

private static class Node {
    int key;
    Node left, right;
    int height;

    Node(int key) {
        this.key = key;
        height = 1;
    }
}

public Node insert(Node node, int key) {
    if (node == null)
        return new Node(key);

    if (key < node.key)
        node.left = insert(node.left, key);
    else if (key > node.key)
        node.right = insert(node.right, key);
    else // duplicate, do nothing
        return node;

    // Update height
    node.height = 1 + Math.max(height(node.left), node.right));

    // Get balance factor
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node.left.key)
        return rightRotate(node);

    // Left Right Case
    if (balance > 1 && key > node.left.key) {
        node.left = leftRotate(node.left);
        return rightRotate(node);
    }

    if (balance < -1 && getBalance(node.right) > 0) {
        node.right = rightRotate(node.right);
        return leftRotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node.right.key)
        return leftRotate(node);

    // Right Left Case
    if (balance < -1 && key < node.right.key) {
        node.right = rightRotate(node.right);
        return leftRotate(node);
    }

    return node;
}


public Node deleteNode(Node root, int key) {
    if (root == null)
        return root;

    if (key < root.key)
        root.left = deleteNode(root.left, key);
    else if (key > root.key)
        root.right = deleteNode(root.right, key);
    else {
        // Node with one or two children
        if (root.left == null || root.right == null) {
            Node temp = null;
            if (root.left != null)
                temp = root.left;
            else
                temp = root.right;

            // Case 1: no child
            if (temp == null) {
                root = null;
            } else // Case 2: one child
                root = temp; // promote the child to take the place
        } else {
            // Case 3: two children: get the in-order successor
            Node temp = minValueNode(root.right);
            root.key = temp.key;
            root.right = deleteNode(root.right, temp.key);
        }
    }

    if (root == null)
        return root;

    // Update height
    root.height = 1 + Math.max(height(root.left), height(root.right));

    int balance = getBalance(root);

    // Left Heavy
    if (balance > 1) {
        if (getBalance(root.left) >=0 )
            return rightRotate(root);
        else {
            root.left = leftRotate(root.left);
            return rightRotate(root);
        }
    }

    // Right Heavy
    if (balance < -1) {
        if (getBalance(root.right) <=0 )
            return leftRotate(root);
        else {
            root.right = rightRotate(root.right);
            return leftRotate(root);
        }
    }

    return root;
}


public Node leftRotate(Node x) {
    Node y = x.right;
    Node T2 = y.left;

    y.left = x;
    x.right = T2;

    x.height = 1 + Math.max(height(x.left), height(x.right));
    y.height = 1 + Math.max(height(y.left, height(y.right));

    return y;
}

