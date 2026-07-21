#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at Beginning
void insertAtBeginning(int value) {

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("%d inserted at the beginning.\n", value);
}

// Insert at End
void insertAtEnd(int value) {

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        printf("%d inserted as the first node.\n", value);
        return;
    }

    struct Node *temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

    printf("%d inserted at the end.\n", value);
}

// Delete by Value
void deleteNode(int value) {

    if(head == NULL) {
        printf("Linked List is Empty.\n");
        return;
    }

    struct Node *temp = head;
    struct Node *previous = NULL;

    // Delete first node
    if(temp->data == value) {
        head = temp->next;
        free(temp);
        printf("%d deleted successfully.\n", value);
        return;
    }

    while(temp != NULL && temp->data != value) {
        previous = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("%d not found.\n", value);
        return;
    }

    previous->next = temp->next;
    free(temp);

    printf("%d deleted successfully.\n", value);
}

// Search
void search(int value) {

    struct Node *temp = head;
    int position = 1;

    while(temp != NULL) {

        if(temp->data == value) {
            printf("%d found at position %d.\n", value, position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("%d not found in the list.\n", value);
}

// Display
void display() {

    if(head == NULL) {
        printf("Linked List is Empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("Linked List:\n");

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {

    int choice, value;

    do {

        printf("\n====== SINGLY LINKED LIST MENU ======\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Display\n");
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
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 5:
                display();
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
