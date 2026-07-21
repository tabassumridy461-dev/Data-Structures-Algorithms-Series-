#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at Beginning
void insertAtBeginning(int value) {

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL) {
        head->prev = newNode;
    }

    head = newNode;

    printf("%d inserted at the beginning.\n", value);
}

// Insert at End
void insertAtEnd(int value) {

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL) {
        newNode->prev = NULL;
        head = newNode;

        printf("%d inserted as the first node.\n", value);
        return;
    }

    struct Node *temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    printf("%d inserted at the end.\n", value);
}

// Delete by Value
void deleteNode(int value) {

    if(head == NULL) {
        printf("Linked List is Empty.\n");
        return;
    }

    struct Node *temp = head;

    while(temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("%d not found.\n", value);
        return;
    }

    if(temp == head) {
        head = temp->next;

        if(head != NULL) {
            head->prev = NULL;
        }
    }
    else {

        temp->prev->next = temp->next;

        if(temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
    }

    free(temp);

    printf("%d deleted successfully.\n", value);
}

// Forward Traversal
void displayForward() {

    if(head == NULL) {
        printf("Linked List is Empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("Forward Traversal:\n");

    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Backward Traversal
void displayBackward() {

    if(head == NULL) {
        printf("Linked List is Empty.\n");
        return;
    }

    struct Node *temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    printf("Backward Traversal:\n");

    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

int main() {

    int choice, value;

    do {

        printf("\n====== DOUBLY LINKED LIST MENU ======\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete\n");
        printf("4. Display Forward\n");
        printf("5. Display Backward\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;

            case 4:
                displayForward();
                break;

            case 5:
                displayBackward();
                break;

            case 6:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}
