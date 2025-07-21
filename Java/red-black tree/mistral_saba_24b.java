import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Random;
class Node {
    boolean color;
    Node left, right, parent;
    int data;

    Node(int data) {
        this.data = data;
        this.color = true; // New nodes are inserted as red
        this.left = this.right = this.parent = null;
    }
}

public class mistral_saba_24b {
    private static final boolean RED = true;
    private static final boolean BLACK = false;
    private Node root;

    private void rotateLeft(Node x) {
        Node y = x.right;
        x.right = y.left;
        if (y.left != null) {
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

    private void rotateRight(Node x) {
        Node y = x.left;
        x.left = y.right;
        if (y.right != null) {
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

    private void fixInsert(Node k) {
        Node u;
        while (k.parent != null && k.parent.color == RED) {
            if (k.parent == k.parent.parent.left) {
                u = k.parent.parent.right;
                if (u != null && u.color == RED) {
                    k.parent.color = BLACK;
                    u.color = BLACK;
                    k.parent.parent.color = RED;
                    k = k.parent.parent;
                } else {
                    if (k == k.parent.right) {
                        k = k.parent;
                        rotateLeft(k);
                    }
                    k.parent.color = BLACK;
                    k.parent.parent.color = RED;
                    rotateRight(k.parent.parent);
                }
            } else {
                u = k.parent.parent.left;
                if (u != null && u.color == RED) {
                    k.parent.color = BLACK;
                    u.color = BLACK;
                    k.parent.parent.color = RED;
                    k = k.parent.parent;
                } else {
                    if (k == k.parent.left) {
                        k = k.parent;
                        rotateRight(k);
                    }
                    k.parent.color = BLACK;
                    k.parent.parent.color = RED;
                    rotateLeft(k.parent.parent);
                }
            }
        }
        root.color = BLACK;
    }

    public void insert(int data) {
        Node node = new Node(data);
        node.parent = null;
        node.data = data;
        node.left = null;
        node.right = null;
        node.color = RED;

        if (root == null) {
            root = node;
        } else {
            Node y = null;
            Node x = root;

            while (x != null) {
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
                node.color = BLACK;
                return;
            }

            if (node.parent.parent == null) {
                return;
            }

            fixInsert(node);
        }
    }

    private void fixDelete(Node x) {
        Node s;
        while (x != root && x.color == BLACK) {
            if (x == x.parent.left) {
                s = x.parent.right;
                if (s.color == RED) {
                    s.color = BLACK;
                    x.parent.color = RED;
                    rotateLeft(x.parent);
                    s = x.parent.right;
                }
                if (s.left.color == BLACK && s.right.color == BLACK) {
                    s.color = RED;
                    x = x.parent;
                } else {
                    if (s.right.color == BLACK) {
                        s.left.color = BLACK;
                        s.color = RED;
                        rotateRight(s);
                        s = x.parent.right;
                    }
                    s.color = x.parent.color;
                    x.parent.color = BLACK;
                    s.right.color = BLACK;
                    rotateLeft(x.parent);
                    x = root;
                }
            } else {
                s = x.parent.left;
                if (s.color == RED) {
                    s.color = BLACK;
                    x.parent.color = RED;
                    rotateRight(x.parent);
                    s = x.parent.left;
                }
                if (s.right.color == BLACK && s.right.color == BLACK) {
                    s.color = RED;
                    x = x.parent;
                } else {
                    if (s.left.color == BLACK) {
                        s.right.color = BLACK;
                        s.color = RED;
                        rotateLeft(s);
                        s = x.parent.left;
                    }
                    s.color = x.parent.color;
                    x.parent.color = BLACK;
                    s.left.color = BLACK;
                    rotateRight(x.parent);
                    x = root;
                }
            }
        }
        x.color = BLACK;
    }

    private void deleteNodeHelper(Node node, int key) {
        Node z = root;
        Node x, y;
        while (z != null && z.data != key) {
            if (z.data > key) {
                z = z.left;
            } else {
                z = z.right;
            }
        }
        if (z == null) {
            return;
        }
        y = z;
        y.color = y.color;
        if (z.left == null) {
            x = z.right;
            x.parent = z.parent;
            if (z.parent == null) {
                root = x;
            } else if (z == z.parent.left) {
                z.parent.left = x;
            } else {
                z.parent.right = x;
            }
        } else if (z.right == null) {
            x = z.left;
            x.parent = z.parent;
            if (z.parent == null) {
                root = x;
            } else if (z == z.parent.left) {
                z.parent.left = x;
            } else {
                z.parent.right = x;
            }
        } else {
            y = z.right;
            while (y.left != null) {
                y = y.left;
            }
            y.color = y.color;
            x = y.right;
            if (y.parent == z) {
                x.parent = y;
            } else {
                x.parent = y.parent;
                y.parent.left = x;
            }
            if (z.parent == null) {
                root = y;
            } else if (z == z.parent.left) {
                z.parent.left = y;
            } else {
                z.parent.right = y;
            }
            y.left = z.left;
            z.left.parent = y;
            y.right = z.right;
            z.right.parent = y;
        }
        if (y.color == BLACK) {
            fixDelete(x);
        }
    }

    public void deleteNode(int data) {
        deleteNodeHelper(this.root, data);
    }

    public void inorder() {
        inorderHelper(this.root);
    }

    private void inorderHelper(Node root) {
        if (root != null) {
            inorderHelper(root.left);
            System.out.print(root.data + " ");
            inorderHelper(root.right);
        }
    }


    public static void main(String[] args) {
        mistral_saba_24b rbt = new mistral_saba_24b();

        try (BufferedReader br = new BufferedReader(new FileReader("../../inputs.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                int value = Integer.parseInt(line.trim());
                rbt.insert(value);
            }
        } catch (IOException e) {
            return;
        }

    }
}

