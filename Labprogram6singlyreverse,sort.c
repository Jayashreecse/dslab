#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void printList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void sortList(struct Node* head) {
    struct Node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                // Swap data
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}


void reverseList(struct Node** head) {
    struct Node* prev = NULL; 
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current; 
        current = next;
    }
    *head = prev;
}


void concatenateLists(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
    } else {
        struct Node* temp = *head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = *head2;
    }
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int choice, data;

    while(1){
        printf("\nSingly Linked List Operations\n");
        printf("1. Insert in List 1\n");
        printf("2. Insert in List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Sort List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate List 1 and List 2\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert in List 1: ");
                scanf("%d", &data);
                insertEnd(&list1, data);
                break;

            case 2:
                printf("Enter data to insert in List 2: ");
                scanf("%d", &data);
                insertEnd(&list2, data);
                break;

            case 3:
                printf("List 1: ");
                printList(list1);
                break;

            case 4:
                printf("List 2: ");
                printList(list2);
                break;

            case 5:
                sortList(list1);
                printf("List 1 after sorting: ");
                printList(list1);
                break;

            case 6:
                reverseList(&list1);
                printf("List 1 after reversing: ");
                printList(list1);
                break;

            case 7:
                concatenateLists(&list1, &list2);
                printf("List 1 after concatenation: ");
                printList(list1);
                break;

            case 8:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } 

    return 0;
}
