#include <stdio.h>

int main() {
    int arr[100];
    int n, i;
    int position, value;

    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display original array
    printf("\nOriginal Array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Update an element
    printf("\n\nEnter the position to update (1-%d): ", n);
    scanf("%d", &position);

    printf("Enter the new value: ");
    scanf("%d", &value);

    if(position >= 1 && position <= n) {
        arr[position - 1] = value;
    } else {
        printf("Invalid Position!\n");
    }

    // Display updated array
    printf("\nArray after Update:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Insert a new element
    printf("\n\nEnter the position to insert (1-%d): ", n + 1);
    scanf("%d", &position);

    printf("Enter the value to insert: ");
    scanf("%d", &value);

    if(position >= 1 && position <= n + 1) {

        for(i = n; i >= position; i--) {
            arr[i] = arr[i - 1];
        }

        arr[position - 1] = value;
        n++;

    } else {
        printf("Invalid Position!\n");
    }

    // Display array after insertion
    printf("\nArray after Insertion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Delete an element
    printf("\n\nEnter the position to delete (1-%d): ", n);
    scanf("%d", &position);

    if(position >= 1 && position <= n) {

        for(i = position - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        n--;

    } else {
        printf("Invalid Position!\n");
    }

    // Display final array
    printf("\nArray after Deletion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
