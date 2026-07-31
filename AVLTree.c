// ============================================
// File: 23_AVLTree.c
// Topic: AVL Tree (Self-Balancing BST)
// Concepts:
// 1. Insert Node
// 2. Left Rotation
// 3. Right Rotation
// 4. Balance Factor
// ============================================

#include <stdio.h>
#include <stdlib.h>

// ------------------------------
// AVL Tree Node
// ------------------------------
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

// ------------------------------
// Return maximum of two numbers
// ------------------------------
int max(int a, int b) {
    return (a > b) ? a : b;
}

// ------------------------------
// Return height of a node
// ------------------------------
int height(struct Node *node) {
    if (node == NULL)
        return 0;

    return node->height;
}

// ------------------------------
// Create a new node
// ------------------------------
struct Node* createNode(int value) {

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

// ------------------------------
// Right Rotation
//
//        y                 x
//       / \               / \
//      x   T3   --->     T1  y
//     / \                   / \
//    T1 T2                 T2 T3
// ------------------------------
struct Node* rightRotate(struct Node *y) {

    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// ------------------------------
// Left Rotation
//
//      x                     y
//     / \                   / \
//    T1  y      --->       x  T3
//       / \               / \
//      T2 T3             T1 T2
// ------------------------------
struct Node* leftRotate(struct Node *x) {

    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// ------------------------------
// Calculate Balance Factor
// ------------------------------
int getBalance(struct Node *node) {

    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

// ------------------------------
// Insert into AVL Tree
// ------------------------------
struct Node* insert(struct Node *node, int value) {

    // Normal BST insertion
    if (node == NULL)
        return createNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);

    else if (value > node->data)
        node->right = insert(node->right, value);

    else
        return node;

    // Update height
    node->height = 1 + max(height(node->left), height(node->right));

    // Check balance
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && value > node->left->data) {

        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->data) {

        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// ------------------------------
// Inorder Traversal
// ------------------------------
void inorder(struct Node *root) {

    if (root != NULL) {

        inorder(root->left);

        printf("%d ", root->data);

        inorder(root->right);
    }
}

// ------------------------------
// Main Function
// ------------------------------
int main() {

    struct Node *root = NULL;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Inorder Traversal of AVL Tree:\n");
    inorder(root);

    return 0;
}
