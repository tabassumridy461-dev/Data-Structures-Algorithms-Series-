

public class Stack {

    // Maximum size of the stack
    private int MAX_SIZE = 5;

    // Array to store stack elements
    private int[] stack = new int[MAX_SIZE];

    // Top points to the last inserted element
    private int top = -1;

    // Push operation
    public void push(int value) {

        // Check if the stack is full
        if (top == MAX_SIZE - 1) {
            System.out.println("Stack Overflow! Cannot insert " + value);
            return;
        }

        // Increase top and insert value
        top++;
        stack[top] = value;

        System.out.println(value + " pushed into the stack.");
    }

    // Pop operation
    public void pop() {

        // Check if the stack is empty
        if (top == -1) {
            System.out.println("Stack Underflow! Stack is empty.");
            return;
        }

        System.out.println(stack[top] + " removed from the stack.");

        // Remove the top element
        top--;
    }

    // Peek operation
    public void peek() {

        if (top == -1) {
            System.out.println("Stack is empty.");
            return;
        }

        System.out.println("Top Element: " + stack[top]);
    }

    // Check if the stack is empty
    public void isEmpty() {

        if (top == -1) {
            System.out.println("Stack is empty.");
        } else {
            System.out.println("Stack is not empty.");
        }

    }

    // Display all elements
    public void display() {

        if (top == -1) {
            System.out.println("Stack is empty.");
            return;
        }

        System.out.print("Stack Elements: ");

        // Print from top to bottom
        for (int i = top; i >= 0; i--) {
            System.out.print(stack[i] + " ");
        }

        System.out.println();
    }

    public static void main(String[] args) {

        // Create Stack object
        Stack stack = new Stack();

        stack.push(10);
        stack.push(20);
        stack.push(30);

        stack.display();

        stack.peek();

        stack.pop();

        stack.display();

        stack.isEmpty();

    }

}
