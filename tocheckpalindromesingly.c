#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list.
struct Node {
    int data;
    struct Node *next;
};

// Function to reverse the linked list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;  // Save the next node
        curr->next = prev;  // Reverse the current node's next pointer
        prev = curr;        // Move prev to current node
        curr = next;        // Move to next node
    }
    return prev;  // Return the new head (previously the last node)
}

struct Node* copyList(struct Node* head) {
    if (head == NULL) return NULL;  // Return NULL if the list is empty

    struct Node* newHead = (struct Node*)malloc(sizeof(struct Node));  // Create the first node
    newHead->data = head->data;  // Copy the data from the original list
    newHead->next = copyList(head->next);  // Recursively copy the rest of the list

    return newHead;  // Return the head of the new list
}


// Function to check if the linked list is a palindrome
bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;  // An empty list or a list with one node is a palindrome
    }

    // Step 1: Create a copy of the linked list
    struct Node* copiedList = copyList(head);

    // Step 2: Reverse the copied list
    struct Node* reversedList = reverseList(copiedList);

    // Step 3: Compare the original list with the reversed list
    struct Node* original = head;
    struct Node* reversed = reversedList;

    while (original != NULL && reversed != NULL) {
        if (original->data != reversed->data) {
            return false;  // If any values don't match, it's not a palindrome
        }
        original = original->next;
        reversed = reversed->next;
    }

    return true;  // If all values match, it's a palindrome
}

// Function to insert a new node at the front of the list
void insertAtFront(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

// Function to print the linked list (for testing purposes)
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to test the isPalindrome function with user input
int main() {
    int n;
    struct Node* head = NULL;  // Initialize an empty list

    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);

    // Insert the nodes at the front (building the list in reverse order)
    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insertAtFront(&head, value);
    }

    // Print the list for confirmation
    printf("The linked list is: ");
    printList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        printf("The list is a palindrome.\n");
    } else {
        printf("The list is not a palindrome.\n");
    }

    return 0;
}
