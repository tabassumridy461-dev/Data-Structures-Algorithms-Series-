#include <stdio.h>

int main() {
    int arr[100];
    int n, i, j;
    int minIndex, temp;

    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Selection Sort
    for(i = 0; i < n - 1; i++) {

        minIndex = i;

        for(j = i + 1; j < n; j++) {

            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }

        }

        // Swap the smallest element with the current position
        if(minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    // Display sorted array
    printf("\nSorted Array (Ascending Order):\n");

    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
