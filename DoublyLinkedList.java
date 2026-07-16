
public class DoublyLinkedList {

    // Node class
    static class Node {

        int data;
        Node previous;
        Node next;

        // Constructor
        Node(int data) {
            this.data = data;
            this.previous = null;
            this.next = null;
        }

    }

    // Head points to the first node
    private Node head = null;

    // Tail points to the last node
    private Node tail = null;

    // Insert a new node at the end
    public void insert(int data) {

        // Create a new node
        Node newNode = new Node(data);

        // If the list is empty
        if (head == null) {
            head = newNode;
            tail = newNode;
            return;
        }

        // Connect the new node with the last node
        tail.next = newNode;
        newNode.previous = tail;

        // Update the tail
        tail = newNode;
    }

    // Display from head to tail
    public void displayForward() {

        if (head == null) {
            System.out.println("Doubly Linked List is empty.");
            return;
        }

        Node current = head;

        System.out.print("Forward: ");

        while (current != null) {

            System.out.print(current.data);

            if (current.next != null) {
                System.out.print(" <-> ");
            }

            current = current.next;
        }

        System.out.println();
    }

    // Display from tail to head
    public void displayBackward() {

        if (tail == null) {
            System.out.println("Doubly Linked List is empty.");
            return;
        }

        Node current = tail;

        System.out.print("Backward: ");

        while (current != null) {

            System.out.print(current.data);

            if (current.previous != null) {
                System.out.print(" <-> ");
            }

            current = current.previous;
        }

        System.out.println();
    }

    public static void main(String[] args) {

        // Create Doubly Linked List object
        DoublyLinkedList list = new DoublyLinkedList();

        // Insert elements
        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);

        // Display list
        list.displayForward();

        list.displayBackward();

    }

}
