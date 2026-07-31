// ============================================
// File: 28_KruskalsAlgorithm.c
// Topic: Kruskal's Algorithm
// Concepts:
// 1. Minimum Spanning Tree (MST)
// 2. Greedy Algorithm
// 3. Union-Find (Disjoint Set)
// ============================================

#include <stdio.h>

#define V 5
#define E 7

// ------------------------------
// Edge Structure
// ------------------------------
struct Edge {

    int source;
    int destination;
    int weight;

};

// ------------------------------
// Parent Array for Union-Find
// ------------------------------
int parent[V];

// ------------------------------
// Make Set
// ------------------------------
void makeSet() {

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }
}

// ------------------------------
// Find Parent
// ------------------------------
int find(int x) {

    if (parent[x] != x)
        parent[x] = find(parent[x]);   // Path Compression

    return parent[x];
}

// ------------------------------
// Union Two Sets
// ------------------------------
void unionSet(int a, int b) {

    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB)
        parent[rootB] = rootA;
}

// ------------------------------
// Bubble Sort Edges by Weight
// ------------------------------
void sortEdges(struct Edge edges[]) {

    for (int i = 0; i < E - 1; i++) {

        for (int j = 0; j < E - i - 1; j++) {

            if (edges[j].weight > edges[j + 1].weight) {

                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// ------------------------------
// Kruskal Algorithm
// ------------------------------
void kruskal(struct Edge edges[]) {

    makeSet();

    sortEdges(edges);

    int totalCost = 0;

    printf("Edges in Minimum Spanning Tree\n\n");

    for (int i = 0; i < E; i++) {

        int u = edges[i].source;
        int v = edges[i].destination;

        // If adding this edge does not create a cycle
        if (find(u) != find(v)) {

            printf("%d -- %d   Weight = %d\n", u, v, edges[i].weight);

            totalCost += edges[i].weight;

            unionSet(u, v);
        }
    }

    printf("\nTotal Cost = %d\n", totalCost);
}

// ------------------------------
// Main Function
// ------------------------------
int main() {

    struct Edge edges[E] = {

        {0,1,2},
        {0,3,6},
        {1,2,3},
        {1,3,8},
        {1,4,5},
        {2,4,7},
        {3,4,9}

    };

    kruskal(edges);

    return 0;
}
