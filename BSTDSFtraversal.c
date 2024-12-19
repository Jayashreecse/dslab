#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary search tree
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

// In-order traversal (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Pre-order traversal (Root, Left, Right)
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Post-order traversal (Left, Right, Root)
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to display the menu and perform actions based on user input
void displayMenu() {
    printf("\nBinary Search Tree Operations:\n");
    printf("1. Insert a node\n");
    printf("2. In-order traversal\n");
    printf("3. Pre-order traversal\n");
    printf("4. Post-order traversal\n");
    printf("5. Exit\n");
}

int main() {
    struct Node* root = NULL;  // Initialize an empty tree
    int choice, data;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Insert a node
                printf("Enter value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:  // In-order traversal
                printf("In-order traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 3:  // Pre-order traversal
                printf("Pre-order traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 4:  // Post-order traversal
                printf("Post-order traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;

            case 5:  // Exit
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
