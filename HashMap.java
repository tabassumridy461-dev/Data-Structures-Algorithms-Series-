
import java.util.HashMap;
import java.util.Map;

public class HashMapExample {

    public static void main(String[] args) {

        // Create a HashMap
        HashMap<Integer, String> students = new HashMap<>();

        // Add key-value pairs
        students.put(101, "Alice");
        students.put(102, "Bob");
        students.put(103, "Charlie");
        students.put(104, "David");

        // Display all data
        System.out.println("Student List:");
        System.out.println(students);

        // Get value using key
        System.out.println("\nStudent with ID 102: " + students.get(102));

        // Check if a key exists
        System.out.println("Contains ID 103: " + students.containsKey(103));

        // Remove an entry
        students.remove(104);

        // Display after removal
        System.out.println("\nAfter Removing ID 104:");
        System.out.println(students);

        // Print all key-value pairs
        System.out.println("\nAll Students:");

        for (Map.Entry<Integer, String> entry : students.entrySet()) {

            System.out.println(
                    "ID: " + entry.getKey()
                            + " | Name: " + entry.getValue()
            );

        }

    }

}
