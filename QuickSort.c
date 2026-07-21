#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(int arr[], int low, int high) {

    // Select the last element as pivot
    int pivot = arr[high];

    int i = low - 1;

    for(int j = low; j < high; j++) {

        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }

    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {

    if(low < high) {

        int pivotIndex = partition(arr, low, high);

        // Sort left part
        quickSort(arr, low, pivotIndex - 1);

        // Sort right part
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {

    int arr[100];
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("\nSorted Array (Ascending Order):\n");

    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
