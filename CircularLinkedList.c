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

    if(head == NULL) {
        newNode->next = newNode;
        head = newNode;
    }
    else {

        struct Node *temp = head;

        while(temp->next != head) {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    printf("%d inserted at the beginning.\n", value);
}

// Insert at End
void insertAtEnd(int value) {

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if(head == NULL) {
        newNode->next = newNode;
        head = newNode;
    }
    else {

        struct Node *temp = head;

        while(temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    printf("%d inserted at the end.\n", value);
}

// Delete by Value
void deleteNode(int value) {

    if(head == NULL) {
        printf("Circular Linked List is Empty.\n");
        return;
    }

    struct Node *current = head;
    struct Node *previous = NULL;

    // Delete head node
    if(head->data == value) {

        // Only one node
        if(head->next == head) {
            free(head);
            head = NULL;
            printf("%d deleted successfully.\n", value);
            return;
        }

        struct Node *last = head;

        while(last->next != head) {
            last = last->next;
        }

        last->next = head->next;

        struct Node *temp = head;
        head = head->next;

        free(temp);

        printf("%d deleted successfully.\n", value);
        return;
    }

    previous = head;
    current = head->next;

    while(current != head && current->data != value) {
        previous = current;
        current = current->next;
    }

    if(current == head) {
        printf("%d not found.\n", value);
        return;
    }

    previous->next = current->next;
    free(current);

    printf("%d deleted successfully.\n", value);
}

// Search
void search(int value) {

    if(head == NULL) {
        printf("Circular Linked List is Empty.\n");
        return;
    }

    struct Node *temp = head;
    int position = 1;

    do {

        if(temp->data == value) {
            printf("%d found at position %d.\n", value, position);
            return;
        }

        temp = temp->next;
        position++;

    } while(temp != head);

    printf("%d not found.\n", value);
}

// Display
void display() {

    if(head == NULL) {
        printf("Circular Linked List is Empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("Circular Linked List:\n");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("(Back to Head)\n");
}

int main() {

    int choice, value;

    do {

        printf("\n====== CIRCULAR LINKED LIST MENU ======\n");
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
