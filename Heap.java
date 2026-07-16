
public class Heap {

    // Maximum size of the heap
    private static final int MAX_SIZE = 10;

    // Array to store heap elements
    private int[] heap = new int[MAX_SIZE];

    // Current number of elements
    private int size = 0;

    // Insert a new element into the Max Heap
    public void insert(int value) {

        // Check if heap is full
        if (size == MAX_SIZE) {
            System.out.println("Heap is full.");
            return;
        }

        // Insert the new value at the end
        heap[size] = value;

        // Restore Max Heap property
        heapifyUp(size);

        // Increase heap size
        size++;

    }

    // Move the inserted element upward if needed
    private void heapifyUp(int index) {

        // Continue until reaching the root
        while (index > 0) {

            // Find parent index
            int parent = (index - 1) / 2;

            // Stop if parent is already larger
            if (heap[parent] >= heap[index]) {
                break;
            }

            // Swap parent and child
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;

            // Move to parent
            index = parent;

        }

    }

    // Display heap elements
    public void display() {

        if (size == 0) {
            System.out.println("Heap is empty.");
            return;
        }

        System.out.print("Heap Elements: ");

        for (int i = 0; i < size; i++) {
            System.out.print(heap[i] + " ");
        }

        System.out.println();

    }

    public static void main(String[] args) {

        // Create Heap object
        Heap heap = new Heap();

        // Insert elements
        heap.insert(40);
        heap.insert(20);
        heap.insert(50);
        heap.insert(10);
        heap.insert(60);
        heap.insert(30);

        // Display Heap
        heap.display();

    }

}
