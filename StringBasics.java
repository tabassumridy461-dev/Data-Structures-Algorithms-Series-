
public class StringBasics {

    public static void main(String[] args) {

        // Create a String
        String text = "Data Structures and Algorithms";

        // Print original String
        System.out.println("Original String: " + text);

        // Find String length
        System.out.println("Length: " + text.length());

        // Get character at a specific index
        System.out.println("Character at index 5: " + text.charAt(5));

        // Convert to uppercase
        System.out.println("Uppercase: " + text.toUpperCase());

        // Convert to lowercase
        System.out.println("Lowercase: " + text.toLowerCase());

        // Check if a word exists
        System.out.println("Contains 'Algorithms': " + text.contains("Algorithms"));

        // Extract a substring
        System.out.println("Substring (5 to 15): " + text.substring(5, 15));

        // Replace a word
        System.out.println("Replace 'Algorithms' with 'Java': "
                + text.replace("Algorithms", "Java"));

        // Compare two Strings
        String anotherText = "Data Structures and Algorithms";

        System.out.println("Strings are equal: " + text.equals(anotherText));

    }
}
