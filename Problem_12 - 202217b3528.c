#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary search tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a node in the binary search tree
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Function to find the rightmost node in a tree
struct Node* findRightmostNode(struct Node* root) {
    struct Node* current = root;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current;
}

// Function to delete a node in the binary tree
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findRightmostNode(root->left);
        root->data = temp->data;
        root->left = deleteNode(root->left, temp->data);
    }
    return root;
}

// Function to print the inorder traversal of the tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int elements[] = {11, 12, 13, 14, 15, 16, 17};
    int n = sizeof(elements) / sizeof(elements[0]);

    // Insert elements into the binary tree
    for (int i = 0; i < n; i++) {
        root = insert(root, elements[i]);
    }

    // Print inorder traversal of the binary tree
    printf("Inorder traversal of the binary tree: ");
    inorderTraversal(root);
    printf("\n");

    // Search for an element in the binary tree
    int key = 15;
    struct Node* foundNode = search(root, key);
    if (foundNode != NULL) {
        printf("Element %d found in the binary tree.\n", key);
    } else {
        printf("Element %d not found in the binary tree.\n", key);
    }

    // Delete an element from the binary tree
    key = 14;
    root = deleteNode(root, key);
    printf("Inorder traversal after deleting %d: ", key);
    inorderTraversal(root);
    printf("\n");

    return 0;
}