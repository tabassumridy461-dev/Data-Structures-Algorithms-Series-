#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    if(n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}

// Function to calculate Fibonacci
int fibonacci(int n) {
    if(n == 0)
        return 0;

    if(n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to calculate sum of first n natural numbers
int sum(int n) {
    if(n == 0)
        return 0;

    return n + sum(n - 1);
}

// Function to calculate power
int power(int base, int exponent) {
    if(exponent == 0)
        return 1;

    return base * power(base, exponent - 1);
}

// Function to reverse a number
void reverse(int n) {
    if(n == 0)
        return;

    printf("%d", n % 10);
    reverse(n / 10);
}

int main() {

    int n;
    int base, exponent;
    int number;

    // Factorial
    printf("Enter a number for factorial: ");
    scanf("%d", &n);

    printf("Factorial = %d\n", factorial(n));

    // Fibonacci
    printf("\nEnter number of Fibonacci terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for(int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\n");

    // Sum
    printf("\nEnter a number to find the sum: ");
    scanf("%d", &n);

    printf("Sum = %d\n", sum(n));

    // Power
    printf("\nEnter base and exponent: ");
    scanf("%d %d", &base, &exponent);

    printf("Result = %d\n", power(base, exponent));

    // Reverse Number
    printf("\nEnter a number to reverse: ");
    scanf("%d", &number);

    printf("Reversed Number = ");
    reverse(number);

    printf("\n");

    return 0;
}
