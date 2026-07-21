#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a New Node
struct Node* createNode(int value) {

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert Node
struct Node* insert(struct Node *root, int value) {

    if(root == NULL) {
        return createNode(value);
    }

    if(value < root->data) {
        root->left = insert(root->left, value);
    }
    else if(value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Search Node
struct Node* search(struct Node *root, int key) {

    if(root == NULL || root->data == key) {
        return root;
    }

    if(key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Inorder Traversal
void inorder(struct Node *root) {

    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder Traversal
void preorder(struct Node *root) {

    if(root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal
void postorder(struct Node *root) {

    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {

    struct Node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder Traversal:\n");
    inorder(root);

    printf("\n\n");

    printf("Preorder Traversal:\n");
    preorder(root);

    printf("\n\n");

    printf("Postorder Traversal:\n");
    postorder(root);

    printf("\n\n");

    int key = 60;

    if(search(root, key) != NULL)
        printf("%d found in the BST.\n", key);
    else
        printf("%d not found in the BST.\n", key);

    return 0;
}
