
public class Queue {

    // Maximum size of the queue
    private final int MAX_SIZE = 5;

    // Array to store queue elements
    private int[] queue = new int[MAX_SIZE];

    // Front points to the first element
    private int front = 0;

    // Rear points to the last inserted element
    private int rear = -1;

    // Number of elements in the queue
    private int size = 0;

    // Enqueue operation
    public void enqueue(int value) {

        // Check if the queue is full
        if (size == MAX_SIZE) {
            System.out.println("Queue Overflow! Cannot insert " + value);
            return;
        }

        // Move rear to the next position
        rear++;

        // Insert the value
        queue[rear] = value;

        // Increase queue size
        size++;

        System.out.println(value + " inserted into the queue.");
    }

    // Dequeue operation
    public void dequeue() {

        // Check if the queue is empty
        if (size == 0) {
            System.out.println("Queue Underflow! Queue is empty.");
            return;
        }

        System.out.println(queue[front] + " removed from the queue.");

        // Move front to the next element
        front++;

        // Decrease queue size
        size--;
    }

    // Peek operation
    public void peek() {

        if (size == 0) {
            System.out.println("Queue is empty.");
            return;
        }

        System.out.println("Front Element: " + queue[front]);
    }

    // Check if queue is empty
    public void isEmpty() {

        if (size == 0) {
            System.out.println("Queue is empty.");
        } else {
            System.out.println("Queue is not empty.");
        }

    }

    // Display all queue elements
    public void display() {

        if (size == 0) {
            System.out.println("Queue is empty.");
            return;
        }

        System.out.print("Queue Elements: ");

        for (int i = front; i <= rear; i++) {
            System.out.print(queue[i] + " ");
        }

        System.out.println();
    }

    public static void main(String[] args) {

        // Create Queue object
        Queue queue = new Queue();

        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);

        queue.display();

        queue.peek();

        queue.dequeue();

        queue.display();

        queue.isEmpty();

    }

}
