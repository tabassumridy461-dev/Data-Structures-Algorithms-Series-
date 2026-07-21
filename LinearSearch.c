#include <stdio.h>

int main() {
    int arr[100];
    int n, i;
    int key;
    int found = 0;

    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the element to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Perform Linear Search
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            found = 1;
            printf("\nElement %d found at position %d.\n", key, i + 1);
            break;
        }
    }

    if(found == 0) {
        printf("\nElement %d not found in the array.\n", key);
    }

    return 0;
}
