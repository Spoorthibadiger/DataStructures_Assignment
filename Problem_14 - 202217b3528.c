#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// In-order traversal (Left, Root, Right)
void inorderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    inorderTraversal(node->left);
    printf("%c ", node->data);
    inorderTraversal(node->right);
}

// Pre-order traversal (Root, Left, Right)
void preorderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%c ", node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Post-order traversal (Left, Right, Root)
void postorderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%c ", node->data);
}

// Main function to demonstrate tree traversal
int main() {
    // Construct the tree as shown in the image
    Node* root = createNode('D');
    root->left = createNode('A');
    root->right = createNode('F');
    
    root->left->left = createNode('E');
    root->left->right = createNode('B');
    
    root->left->left->left = createNode('G');
    root->left->left->right = createNode('Q');
    
    root->right->left = createNode('R');
    root->right->right = createNode('T');
    
    root->right->left->left = createNode('V');
    root->right->right->left = createNode('J');
    root->right->right->right = createNode('L');
    
    // Perform the different traversals
    printf("Pre-order Traversal: ");
    preorderTraversal(root);
    printf("\n");
    
    printf("Post-order Traversal: ");
    postorderTraversal(root);
    printf("\n");
    
    printf("In-order Traversal: ");
    inorderTraversal(root);
    printf("\n");
    
    return 0;
}