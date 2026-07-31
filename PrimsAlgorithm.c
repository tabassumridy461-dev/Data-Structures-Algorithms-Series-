// ============================================
// File: 27_PrimsAlgorithm.c
// Topic: Prim's Algorithm
// Concepts:
// 1. Minimum Spanning Tree (MST)
// 2. Greedy Algorithm
// 3. Adjacency Matrix
// ============================================

#include <stdio.h>

#define V 5
#define INF 9999

// ------------------------------
// Find the vertex with minimum key
// that is not included in MST
// ------------------------------
int minKey(int key[], int mstSet[]) {

    int min = INF;
    int minIndex = -1;

    for (int i = 0; i < V; i++) {

        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// ------------------------------
// Print the MST
// ------------------------------
void printMST(int parent[], int graph[V][V]) {

    int totalCost = 0;

    printf("Edge\tWeight\n");

    for (int i = 1; i < V; i++) {

        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }

    printf("\nTotal Cost of MST = %d\n", totalCost);
}

// ------------------------------
// Prim's Algorithm
// ------------------------------
void primMST(int graph[V][V]) {

    int parent[V];   // Store MST
    int key[V];      // Minimum edge weight
    int mstSet[V];   // Included in MST or not

    // Initialize arrays
    for (int i = 0; i < V; i++) {

        key[i] = INF;
        mstSet[i] = 0;
    }

    // Start from vertex 0
    key[0] = 0;
    parent[0] = -1;

    // Build MST
    for (int count = 0; count < V - 1; count++) {

        int u = minKey(key, mstSet);

        mstSet[u] = 1;

        // Update adjacent vertices
        for (int v = 0; v < V; v++) {

            if (graph[u][v] &&
                !mstSet[v] &&
                graph[u][v] < key[v]) {

                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

// ------------------------------
// Main Function
// ------------------------------
int main() {

    int graph[V][V] = {

    // 0  1  2  3  4

        {0, 2, 0, 6, 0}, // 0
        {2, 0, 3, 8, 5}, // 1
        {0, 3, 0, 0, 7}, // 2
        {6, 8, 0, 0, 9}, // 3
        {0, 5, 7, 9, 0}  // 4
    };

    primMST(graph);

    return 0;
}
