// ============================================
// File: 29_FloydWarshall.c
// Topic: Floyd-Warshall Algorithm
// Concepts:
// 1. All-Pairs Shortest Path
// 2. Dynamic Programming
// 3. Adjacency Matrix
// ============================================

#include <stdio.h>

#define V 4
#define INF 99999   // Represents infinity

// ------------------------------
// Print the distance matrix
// ------------------------------
void printMatrix(int dist[V][V]) {

    printf("Shortest Distance Matrix:\n\n");

    for (int i = 0; i < V; i++) {

        for (int j = 0; j < V; j++) {

            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }

        printf("\n");
    }
}

// ------------------------------
// Floyd-Warshall Algorithm
// ------------------------------
void floydWarshall(int graph[V][V]) {

    int dist[V][V];

    // Copy graph into distance matrix
    for (int i = 0; i < V; i++) {

        for (int j = 0; j < V; j++) {

            dist[i][j] = graph[i][j];
        }
    }

    // Try every vertex as an intermediate vertex
    for (int k = 0; k < V; k++) {

        for (int i = 0; i < V; i++) {

            for (int j = 0; j < V; j++) {

                if (dist[i][k] != INF &&
                    dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printMatrix(dist);
}

// ------------------------------
// Main Function
// ------------------------------
int main() {

    int graph[V][V] = {

        //0     1      2      3
        {0,     5,     INF,   10},
        {INF,   0,     3,     INF},
        {INF,   INF,   0,     1},
        {INF,   INF,   INF,   0}

    };

    floydWarshall(graph);

    return 0;
}
