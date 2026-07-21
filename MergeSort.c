#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArray[n1], rightArray[n2];

    // Copy data to temporary arrays
    for(i = 0; i < n1; i++) {
        leftArray[i] = arr[left + i];
    }

    for(j = 0; j < n2; j++) {
        rightArray[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    // Merge the temporary arrays
    while(i < n1 && j < n2) {

        if(leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements of leftArray
    while(i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArray
    while(j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {

    if(left < right) {

        int mid = (left + right) / 2;

        // Sort left half
        mergeSort(arr, left, mid);

        // Sort right half
        mergeSort(arr, mid + 1, right);

        // Merge both halves
        merge(arr, left, mid, right);
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

    mergeSort(arr, 0, n - 1);

    printf("\nSorted Array (Ascending Order):\n");

    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
