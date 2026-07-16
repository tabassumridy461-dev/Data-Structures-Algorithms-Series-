
public class BinarySearchTree {

    // Node class
    static class Node {

        int data;
        Node left;
        Node right;

        // Constructor
        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }

    }

    // Root node
    Node root;

    // Constructor
    public BinarySearchTree() {
        root = null;
    }

    // Insert a new node
    public Node insert(Node node, int data) {

        // If the tree is empty, create a new node
        if (node == null) {
            return new Node(data);
        }

        // Insert into the left subtree
        if (data < node.data) {
            node.left = insert(node.left, data);
        }

        // Insert into the right subtree
        else if (data > node.data) {
            node.right = insert(node.right, data);
        }

        return node;
    }

    // Search for a value
    public boolean search(Node node, int key) {

        // Value not found
        if (node == null) {
            return false;
        }

        // Value found
        if (node.data == key) {
            return true;
        }

        // Search left subtree
        if (key < node.data) {
            return search(node.left, key);
        }

        // Search right subtree
        return search(node.right, key);

    }

    // Inorder Traversal (Left -> Root -> Right)
    public void inorder(Node node) {

        if (node == null) {
            return;
        }

        inorder(node.left);

        System.out.print(node.data + " ");

        inorder(node.right);

    }

    public static void main(String[] args) {

        // Create Binary Search Tree
        BinarySearchTree bst = new BinarySearchTree();

        // Insert nodes
        bst.root = bst.insert(bst.root, 50);
        bst.root = bst.insert(bst.root, 30);
        bst.root = bst.insert(bst.root, 70);
        bst.root = bst.insert(bst.root, 20);
        bst.root = bst.insert(bst.root, 40);
        bst.root = bst.insert(bst.root, 60);
        bst.root = bst.insert(bst.root, 80);

        // Print tree in sorted order
        System.out.print("Inorder Traversal: ");
        bst.inorder(bst.root);

        System.out.println();

        // Search for elements
        System.out.println("Search 40: " + bst.search(bst.root, 40));
        System.out.println("Search 90: " + bst.search(bst.root, 90));

    }

}
