
public class CircularLinkedList {

    // Node class
    static class Node {

        int data;
        Node next;

        // Constructor
        Node(int data) {
            this.data = data;
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

            // Last node points back to the first node
            tail.next = head;

            return;
        }

        // Connect the new node after the tail
        tail.next = newNode;

        // Update the tail
        tail = newNode;

        // Make the last node point to the head
        tail.next = head;

    }

    // Display all nodes
    public void display() {

        // Check if list is empty
        if (head == null) {
            System.out.println("Circular Linked List is empty.");
            return;
        }

        Node current = head;

        System.out.print("Circular Linked List: ");

        do {

            System.out.print(current.data);

            current = current.next;

            if (current != head) {
                System.out.print(" -> ");
            }

        } while (current != head);

        System.out.println();

    }

    public static void main(String[] args) {

        // Create Circular Linked List object
        CircularLinkedList list = new CircularLinkedList();

        // Insert elements
        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);

        // Display the list
        list.display();

    }

}
