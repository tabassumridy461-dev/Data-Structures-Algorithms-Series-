// 01-LinearSearch.java

public class LinearSearch {

    // Method to perform Linear Search
    public static int linearSearch(int[] array, int target) {

        // Traverse each element one by one
        for (int i = 0; i < array.length; i++) {

            // Check if current element is equal to target
            if (array[i] == target) {
                return i; // Return index if found
            }

        }

        // Return -1 if target is not found
        return -1;
    }

    public static void main(String[] args) {

        // Sample array
        int[] numbers = {12, 25, 8, 45, 30, 18};

        // Number to search
        int target = 45;

        // Call Linear Search method
        int result = linearSearch(numbers, target);

        // Check result
        if (result != -1) {
            System.out.println("Element found at index: " + result);
        } else {
            System.out.println("Element not found.");
        }

    }
}
