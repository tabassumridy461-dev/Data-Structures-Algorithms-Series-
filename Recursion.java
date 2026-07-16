

public class Recursion {

    // Recursive method to calculate factorial
    public static int factorial(int number) {

        // Base Case
        if (number == 0 || number == 1) {
            return 1;
        }

        // Recursive Case
        return number * factorial(number - 1);

    }

    public static void main(String[] args) {

        int number = 5;

        System.out.println("Number: " + number);

        System.out.println("Factorial: " + factorial(number));

    }

}
