
public class ArrayBasics {

    // Method to print all array elements
    public static void printArray(int[] array) {

        for (int number : array) {
            System.out.print(number + " ");
        }

        System.out.println();
    }

    // Method to calculate sum of array elements
    public static int findSum(int[] array) {

        int sum = 0;

        for (int number : array) {
            sum += number;
        }

        return sum;
    }

    // Method to find the largest element
    public static int findMaximum(int[] array) {

        int maximum = array[0];

        for (int number : array) {

            if (number > maximum) {
                maximum = number;
            }

        }

        return maximum;
    }

    // Method to find the smallest element
    public static int findMinimum(int[] array) {

        int minimum = array[0];

        for (int number : array) {

            if (number < minimum) {
                minimum = number;
            }

        }

        return minimum;
    }

    public static void main(String[] args) {

        // Create an integer array
        int[] numbers = {15, 8, 22, 4, 30, 10};

        System.out.println("Array Elements:");
        printArray(numbers);

        System.out.println("Array Length: " + numbers.length);

        System.out.println("Sum: " + findSum(numbers));

        System.out.println("Maximum: " + findMaximum(numbers));

        System.out.println("Minimum: " + findMinimum(numbers));

    }
}
