
public class QuickSort {

    // Method to perform Quick Sort
    public static void quickSort(int[] array, int low, int high) {

        // Check if there is more than one element
        if (low < high) {

            // Find the partition index
            int partitionIndex = partition(array, low, high);

            // Sort the left part
            quickSort(array, low, partitionIndex - 1);

            // Sort the right part
            quickSort(array, partitionIndex + 1, high);

        }

    }

    // Method to partition the array
    public static int partition(int[] array, int low, int high) {

        // Choose the last element as pivot
        int pivot = array[high];

        // Index of smaller element
        int i = low - 1;

        // Compare each element with the pivot
        for (int j = low; j < high; j++) {

            // If current element is smaller than or equal to pivot
            if (array[j] <= pivot) {

                i++;

                // Swap array[i] and array[j]
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;

            }

        }

        // Place pivot in its correct position
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        // Return pivot index
        return i + 1;
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
        int[] numbers = {10, 7, 8, 9, 1, 5};

        System.out.println("Before Sorting:");
        printArray(numbers);

        // Call Quick Sort
        quickSort(numbers, 0, numbers.length - 1);

        System.out.println("After Sorting:");
        printArray(numbers);

    }
}
