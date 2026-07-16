

public class SelectionSort {

    // Method to perform Selection Sort
    public static void selectionSort(int[] array) {

        // Get array size
        int n = array.length;

        // Move boundary of unsorted array
        for (int i = 0; i < n - 1; i++) {

            // Assume the first unsorted element is the smallest
            int minIndex = i;

            // Find the smallest element in the remaining array
            for (int j = i + 1; j < n; j++) {

                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }

            }

            // Swap the smallest element with the current element
            int temp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = temp;

        }

    }

    // Method to print array
    public static void printArray(int[] array) {

        for (int number : array) {
            System.out.print(number + " ");
        }

        System.out.println();
    }

    public static void main(String[] args) {

        // Unsorted array
        int[] numbers = {29, 10, 14, 37, 13};

        System.out.println("Before Sorting:");
        printArray(numbers);

        // Call Selection Sort
        selectionSort(numbers);

        System.out.println("After Sorting:");
        printArray(numbers);

    }
}
