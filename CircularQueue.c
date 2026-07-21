#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Enqueue Operation
void enqueue(int value) {

    // Check Overflow
    if((rear + 1) % MAX == front) {
        printf("Queue Overflow!\n");
        return;
    }

    // First Element
    if(front == -1) {
        front = 0;
        rear = 0;
    }
    else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;

    printf("%d inserted into the queue.\n", value);
}

// Dequeue Operation
void dequeue() {

    // Check Underflow
    if(front == -1) {
        printf("Queue Underflow!\n");
        return;
    }

    printf("%d removed from the queue.\n", queue[front]);

    // Queue becomes empty
    if(front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front + 1) % MAX;
    }
}

// Peek Operation
void peek() {

    if(front == -1) {
        printf("Queue is Empty.\n");
        return;
    }

    printf("Front Element = %d\n", queue[front]);
}

// Display Queue
void display() {

    if(front == -1) {
        printf("Queue is Empty.\n");
        return;
    }

    printf("Queue Elements:\n");

    int i = front;

    while(1) {

        printf("%d ", queue[i]);

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {

    int choice, value;

    do {

        printf("\n====== CIRCULAR QUEUE MENU ======\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 5);

    return 0;
}
