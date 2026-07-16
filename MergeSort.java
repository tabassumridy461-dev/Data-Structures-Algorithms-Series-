
public class MergeSort {

    // Method to divide the array
    public static void mergeSort(int[] array, int left, int right) {

        // Check if there is more than one element
        if (left < right) {

            // Find the middle index
            int middle = (left + right) / 2;

            // Sort the left half
            mergeSort(array, left, middle);

            // Sort the right half
            mergeSort(array, middle + 1, right);

            // Merge the two sorted halves
            merge(array, left, middle, right);
        }

    }

    // Method to merge two sorted subarrays
    public static void merge(int[] array, int left, int middle, int right) {

        // Calculate sizes of left and right subarrays
        int leftSize = middle - left + 1;
        int rightSize = right - middle;

        // Create temporary arrays
        int[] leftArray = new int[leftSize];
        int[] rightArray = new int[rightSize];

        // Copy data into left temporary array
        for (int i = 0; i < leftSize; i++) {
            leftArray[i] = array[left + i];
        }

        // Copy data into right temporary array
        for (int j = 0; j < rightSize; j++) {
            rightArray[j] = array[middle + 1 + j];
        }

        // Initial indexes
        int i = 0;
        int j = 0;
        int k = left;

        // Merge the temporary arrays
        while (i < leftSize && j < rightSize) {

            if (leftArray[i] <= rightArray[j]) {
                array[k] = leftArray[i];
                i++;
            } else {
                array[k] = rightArray[j];
                j++;
            }

            k++;
        }

        // Copy remaining elements of leftArray
        while (i < leftSize) {
            array[k] = leftArray[i];
            i++;
            k++;
        }

        // Copy remaining elements of rightArray
        while (j < rightSize) {
            array[k] = rightArray[j];
            j++;
            k++;
        }

    }

    // Method to print the array
    public static void printArray(int[] array) {

        for (int number : array) {
            System.out.print(number + " ");
        }

        System.out.println();
    }

    public static void main(String[] args) {

        // Unsorted array
        int[] numbers = {38, 27, 43, 3, 9, 82, 10};

        System.out.println("Before Sorting:");
        printArray(numbers);

        // Call Merge Sort
        mergeSort(numbers, 0, numbers.length - 1);

        System.out.println("After Sorting:");
        printArray(numbers);

    }
}
