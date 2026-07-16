

public class GraphBasics {

    // Number of vertices
    private int vertices;

    // Adjacency Matrix
    private int[][] adjacencyMatrix;

    // Constructor
    public GraphBasics(int vertices) {

        this.vertices = vertices;

        // Create the matrix
        adjacencyMatrix = new int[vertices][vertices];

    }

    // Add an edge between two vertices
    public void addEdge(int source, int destination) {

        // Undirected Graph
        adjacencyMatrix[source][destination] = 1;
        adjacencyMatrix[destination][source] = 1;

    }

    // Display the adjacency matrix
    public void displayGraph() {

        System.out.println("Adjacency Matrix:");

        for (int i = 0; i < vertices; i++) {

            for (int j = 0; j < vertices; j++) {

                System.out.print(adjacencyMatrix[i][j] + " ");

            }

            System.out.println();

        }

    }

    public static void main(String[] args) {

        // Create a graph with 5 vertices
        GraphBasics graph = new GraphBasics(5);

        // Add edges
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 3);
        graph.addEdge(2, 4);
        graph.addEdge(3, 4);

        // Display graph
        graph.displayGraph();

    }

}
