// ============================================
// File: 26_DijkstraAlgorithm.c
// Topic: Dijkstra's Algorithm
// Concepts:
// 1. Single Source Shortest Path
// 2. Greedy Algorithm
// 3. Adjacency Matrix
// ============================================

#include <stdio.h>

#define V 5      // Number of vertices
#define INF 9999 // Represents infinity

// ------------------------------
// Find the vertex with minimum distance
// that has not been visited yet
// ------------------------------
int minDistance(int dist[], int visited[]) {

    int min = INF;
    int minIndex = -1;

    for (int i = 0; i < V; i++) {

        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// ------------------------------
// Dijkstra Algorithm
// ------------------------------
void dijkstra(int graph[V][V], int source) {

    int dist[V];       // Shortest distance from source
    int visited[V];    // Visited vertices

    // Initialize arrays
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    // Distance from source to itself is 0
    dist[source] = 0;

    // Process all vertices
    for (int count = 0; count < V - 1; count++) {

        // Pick the nearest unvisited vertex
        int u = minDistance(dist, visited);

        visited[u] = 1;

        // Update distances of adjacent vertices
        for (int v = 0; v < V; v++) {

            if (!visited[v] &&
                graph[u][v] != 0 &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Display result
    printf("Vertex\tShortest Distance from %d\n", source);

    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

// ------------------------------
// Main Function
// ------------------------------
int main() {

    // Weighted Graph (Adjacency Matrix)
    int graph[V][V] = {

        //0  1  2  3  4
        {0,10, 3, 0, 0}, // 0
        {10,0, 1, 2, 0}, // 1
        {3, 1, 0, 8, 2}, // 2
        {0, 2, 8, 0, 7}, // 3
        {0, 0, 2, 7, 0}  // 4
    };

    // Source Vertex = 0
    dijkstra(graph, 0);

    return 0;
}
