#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

// Stack Operations
void push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d to the stack\n", data);
}


int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    struct Node* temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedValue;
}

void displayStack(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack (Top -> Bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Queue Operations
void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*rear == NULL) {
        *front = *rear = newNode;  // If the queue is empty, front and rear will both point to newNode
    } else {
        (*rear)->next = newNode;
        *rear = newNode;  // Move the rear to the new node
    }
    printf("Enqueued %d to the queue\n", data);
}

int dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    struct Node* temp = *front;
    int dequeuedValue = temp->data;
    *front = (*front)->next;
    if (*front == NULL) {  // If the queue becomes empty after dequeue
        *rear = NULL;
    }
    free(temp);
    return dequeuedValue;
}

void displayQueue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue (Front -> Rear): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* stackTop = NULL;
    struct Node* queueFront = NULL;
    struct Node* queueRear = NULL;

    int choice, data;
    do {
        printf("\nMenu:\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Stack operations
                {
                    int stackChoice;
                    do {
                        printf("\nStack Operations:\n");
                        printf("1. Push\n");
                        printf("2. Pop\n");
                        printf("3. Display Stack\n");
                        printf("4. Back to Main Menu\n");
                        printf("Enter your choice: ");
                        scanf("%d", &stackChoice);

                        switch (stackChoice) {
                            case 1:
                                printf("Enter data to push: ");
                                scanf("%d", &data);
                                push(&stackTop, data);
                                break;
                            case 2:
                                data = pop(&stackTop);
                                if (data != -1) {
                                    printf("Popped %d from the stack\n", data);
                                }
                                break;
                            case 3:
                                displayStack(stackTop);
                                break;
                            case 4:
                                printf("Returning to Main Menu...\n");
                                break;
                            default:
                                printf("Invalid choice!\n");
                        }
                    } while (stackChoice != 4);  // Loop until the user chooses to return to the main menu
                }
                break;

            case 2:  // Queue operations
                {
                    int queueChoice;
                    do {
                        printf("\nQueue Operations:\n");
                        printf("1. Enqueue\n");
                        printf("2. Dequeue\n");
                        printf("3. Display Queue\n");
                        printf("4. Back to Main Menu\n");
                        printf("Enter your choice: ");
                        scanf("%d", &queueChoice);

                        switch (queueChoice) {
                            case 1:
                                printf("Enter data to enqueue: ");
                                scanf("%d", &data);
                                enqueue(&queueFront, &queueRear, data);
                                break;
                            case 2:
                                data = dequeue(&queueFront, &queueRear);
                                if (data != -1) {
                                    printf("Dequeued %d from the queue\n", data);
                                }
                                break;
                            case 3:
                                displayQueue(queueFront);
                                break;
                            case 4:
                                printf("Returning to Main Menu...\n");
                                break;
                            default:
                                printf("Invalid choice!\n");
                        }
                    } while (queueChoice != 4);  // Loop until the user chooses to return to the main menu
                }
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);  // Loop until the user chooses to exit the program

    return 0;
}
