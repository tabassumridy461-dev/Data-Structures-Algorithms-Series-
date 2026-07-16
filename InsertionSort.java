

public class InsertionSort {

    // Method to perform Insertion Sort
    public static void insertionSort(int[] array) {

        // Start from the second element
        for (int i = 1; i < array.length; i++) {

            // Store the current element
            int key = array[i];

            // Previous index
            int j = i - 1;

            // Shift elements that are greater than key
            // to one position ahead
            while (j >= 0 && array[j] > key) {

                array[j + 1] = array[j];
                j--;

            }

            // Insert the key into its correct position
            array[j + 1] = key;

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
        int[] numbers = {12, 11, 13, 5, 6};

        System.out.println("Before Sorting:");
        printArray(numbers);

        // Call Insertion Sort
        insertionSort(numbers);

        System.out.println("After Sorting:");
        printArray(numbers);

    }
}
