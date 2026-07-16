// 02-BinarySearch.java

public class BinarySearch {

    // Method to perform Binary Search
    public static int binarySearch(int[] array, int target) {

        // Starting index
        int left = 0;

        // Ending index
        int right = array.length - 1;

        // Repeat until left becomes greater than right
        while (left <= right) {

            // Find middle index
            int middle = left + (right - left) / 2;

            // If target is found
            if (array[middle] == target) {
                return middle;
            }

            // If target is greater than middle element,
            // search in the right half
            if (array[middle] < target) {
                left = middle + 1;
            }

            // Otherwise search in the left half
            else {
                right = middle - 1;
            }

        }

        // Target not found
        return -1;
    }

    public static void main(String[] args) {

        // Binary Search works only on a sorted array
        int[] numbers = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};

        // Number to search
        int target = 35;

        // Call Binary Search
        int result = binarySearch(numbers, target);

        // Display result
        if (result != -1) {
            System.out.println("Element found at index: " + result);
        } else {
            System.out.println("Element not found.");
        }

    }
}
