// 03-BubbleSort.java

public class BubbleSort {

    // Method to perform Bubble Sort
    public static void bubbleSort(int[] array) {

        // Get array size
        int n = array.length;

        // Outer loop for each pass
        for (int i = 0; i < n - 1; i++) {

            // Inner loop for comparing adjacent elements
            for (int j = 0; j < n - i - 1; j++) {

                // Swap if current element is greater than next element
                if (array[j] > array[j + 1]) {

                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;

                }

            }

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
        int[] numbers = {64, 34, 25, 12, 22, 11, 90};

        System.out.println("Before Sorting:");
        printArray(numbers);

        // Call Bubble Sort
        bubbleSort(numbers);

        System.out.println("After Sorting:");
        printArray(numbers);

    }
}
