#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

// Initialize Hash Table
void initialize() {

    for(int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

}

// Hash Function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert
void insert(int key) {

    int index = hashFunction(key);
    int originalIndex = index;

    while(hashTable[index] != -1) {

        index = (index + 1) % SIZE;

        if(index == originalIndex) {
            printf("Hash Table is Full!\n");
            return;
        }
    }

    hashTable[index] = key;

    printf("%d inserted at index %d.\n", key, index);
}

// Search
void search(int key) {

    int index = hashFunction(key);
    int originalIndex = index;

    while(hashTable[index] != -1) {

        if(hashTable[index] == key) {
            printf("%d found at index %d.\n", key, index);
            return;
        }

        index = (index + 1) % SIZE;

        if(index == originalIndex)
            break;
    }

    printf("%d not found.\n", key);
}

// Display
void display() {

    printf("\nHash Table\n");
    printf("----------------------\n");

    for(int i = 0; i < SIZE; i++) {

        if(hashTable[i] == -1)
            printf("%d --> Empty\n", i);
        else
            printf("%d --> %d\n", i, hashTable[i]);

    }
}

int main() {

    int choice;
    int key;

    initialize();

    do {

        printf("\n====== HASH TABLE MENU ======\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:

                printf("Enter key: ");
                scanf("%d", &key);

                insert(key);

                break;

            case 2:

                printf("Enter key to search: ");
                scanf("%d", &key);

                search(key);

                break;

            case 3:

                display();

                break;

            case 4:

                printf("Program Ended.\n");

                break;

            default:

                printf("Invalid Choice!\n");

        }

    } while(choice != 4);

    return 0;
}
