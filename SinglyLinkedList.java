

public class SinglyLinkedList {

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

    // Insert a new node at the end
    public void insert(int data) {

        // Create a new node
        Node newNode = new Node(data);

        // If the list is empty
        if (head == null) {
            head = newNode;
            return;
        }

        // Traverse to the last node
        Node current = head;

        while (current.next != null) {
            current = current.next;
        }

        // Link the last node with the new node
        current.next = newNode;
    }

    // Display all nodes
    public void display() {

        // Check if list is empty
        if (head == null) {
            System.out.println("Linked List is empty.");
            return;
        }

        Node current = head;

        System.out.print("Linked List: ");

        while (current != null) {

            System.out.print(current.data);

            if (current.next != null) {
                System.out.print(" -> ");
            }

            current = current.next;
        }

        System.out.println();
    }

    // Count total nodes
    public int countNodes() {

        int count = 0;

        Node current = head;

        while (current != null) {

            count++;
            current = current.next;

        }

        return count;
    }

    public static void main(String[] args) {

        // Create Linked List object
        SinglyLinkedList list = new SinglyLinkedList();

        // Insert elements
        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);

        // Display Linked List
        list.display();

        // Count nodes
        System.out.println("Total Nodes: " + list.countNodes());

    }

}
