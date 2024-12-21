#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
struct Node {
    int data;           // Holds the value of the node
    struct Node* prev;  // Points to the previous node
    struct Node* next;  // Points to the next node
};

// Declare the head of the list globally
struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Function to create a doubly linked list
void createList() {
    int value, choice;
    struct Node* temp;
   
    do {
        // Prompt user to enter a value
        printf("Enter value to insert: ");
        scanf("%d", &value);

        // Create a new node with the entered value
        struct Node* newNode = createNode(value);
       
        if (head == NULL) {
            head = newNode;  // If the list is empty, the new node becomes the head
        } else {
            temp = head;
            // Traverse to the last node
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;  // Update the last node's next pointer
            newNode->prev = temp;  // Set the new node's previous pointer to the last node
        }

        // Ask user if they want to add another node
        printf("Do you want to add another node? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    } while (choice != 0);
}

// Function to insert a new node to the left of a specific node
void insertLeft(int value, int target) {
    struct Node* temp = head;
   
    // Search for the node with the target value
    while (temp != NULL && temp->data != target) {
        temp = temp->next;  // Traverse the list to find the target node
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", target);
        return;
    }

    // Create a new node to insert
    struct Node* newNode = createNode(value);
   
    // Insert the new node to the left of the target node
    newNode->next = temp;
    newNode->prev = temp->prev;

    // Update the previous node's next pointer, if it exists
    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        head = newNode;  // If inserting at the head, update the head pointer
    }

    // Update the target node's previous pointer
    temp->prev = newNode;

    printf("Node with value %d inserted to the left of %d.\n", value, target);
}

// Function to delete a node based on a specific value
void deleteNode(int value) {
    struct Node* temp = head;

    // Search for the node to delete
    while (temp != NULL && temp->data != value) {
        temp = temp->next;  // Traverse to find the node with the given value
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    // If the node has a previous node, update its next pointer
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;  // If deleting the head, update the head pointer
    }

    // If the node has a next node, update its previous pointer
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);  // Free the memory of the deleted node
    printf("Node with value %d deleted.\n", value);
}

// Function to display the contents of the doubly linked list
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    // Traverse the list and print each node's data
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function with a menu-driven approach
int main() {
    int choice, value, target;

    do {
        // Display the menu
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Create a doubly linked list\n");
        printf("2. Insert a new node to the left of a specific node\n");
        printf("3. Delete a node based on specific value\n");
        printf("4. Display the contents of the list\n");
        printf("5. Exit\n");

        // Ask user for their choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList();  // Create a new doubly linked list
                break;
            case 2:
                // Ask user for the value to insert and the target node
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter target value (left of which node to insert): ");
                scanf("%d", &target);
                insertLeft(value, target);  // Insert the node to the left of the target node
                break;
            case 3:
                // Ask user for the value of the node to delete
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);  // Delete the node with the specified value
                break;
            case 4:
                displayList();  // Display the contents of the list
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);  // Repeat until the user chooses to exit

    return 0;
}
