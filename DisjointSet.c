// ============================================
// File: 25_DisjointSet.c
// Topic: Disjoint Set (Union-Find)
// Concepts:
// 1. Make Set
// 2. Find with Path Compression
// 3. Union
// ============================================

#include <stdio.h>

#define SIZE 10

// ------------------------------
// Parent array
// ------------------------------
int parent[SIZE];

// ------------------------------
// Initialize each element
// Every element is its own parent
// ------------------------------
void makeSet(int n) {

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

// ------------------------------
// Find Parent
// Path Compression is used
// ------------------------------
int find(int x) {

    if (parent[x] != x) {

        // Compress path
        parent[x] = find(parent[x]);
    }

    return parent[x];
}

// ------------------------------
// Union of two sets
// ------------------------------
void unionSet(int a, int b) {

    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB) {

        // Connect one root to another
        parent[rootB] = rootA;
    }
}

// ------------------------------
// Display Parent Array
// ------------------------------
void display(int n) {

    printf("\nElement : Parent\n");

    for (int i = 0; i < n; i++) {

        printf("%4d -> %d\n", i, parent[i]);
    }
}

// ------------------------------
// Main Function
// ------------------------------
int main() {

    int n = 7;

    // Create 7 separate sets
    makeSet(n);

    // Perform Union operations
    unionSet(0, 1);
    unionSet(1, 2);
    unionSet(3, 4);
    unionSet(5, 6);
    unionSet(2, 6);

    display(n);

    printf("\nRepresentative of 6 = %d\n", find(6));
    printf("Representative of 4 = %d\n", find(4));

    // Check if two elements are in the same set
    if (find(0) == find(6))
        printf("\n0 and 6 are in the SAME set.\n");
    else
        printf("\n0 and 6 are in DIFFERENT sets.\n");

    if (find(3) == find(5))
        printf("3 and 5 are in the SAME set.\n");
    else
        printf("3 and 5 are in DIFFERENT sets.\n");

    return 0;
}
