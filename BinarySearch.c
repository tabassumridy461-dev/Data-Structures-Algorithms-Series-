#include <stdio.h>

int main() {
    int arr[100];
    int n, i;
    int key;
    int left, right, mid;
    int found = 0;

    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input sorted array elements
    printf("Enter %d sorted elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the element to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    left = 0;
    right = n - 1;

    // Binary Search
    while(left <= right) {

        mid = (left + right) / 2;

        if(arr[mid] == key) {
            found = 1;
            printf("\nElement %d found at position %d.\n", key, mid + 1);
            break;
        }
        else if(arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if(found == 0) {
        printf("\nElement %d not found in the array.\n", key);
    }

    return 0;
}
