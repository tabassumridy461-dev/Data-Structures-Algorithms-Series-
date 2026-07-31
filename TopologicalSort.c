// ============================================
// File: 30_TopologicalSort.c
// Topic: Topological Sort using DFS
// Concepts:
// 1. Directed Acyclic Graph (DAG)
// 2. Depth First Search (DFS)
// 3. Stack
// ============================================

#include <stdio.h>

#define V 6

// ------------------------------
// Graph (Adjacency Matrix)
// ------------------------------
int graph[V][V] = {

 //0 1 2 3 4 5
  {0,1,1,0,0,0}, // 0 -> 1,2
  {0,0,0,1,0,0}, // 1 -> 3
  {0,0,0,1,1,0}, // 2 -> 3,4
  {0,0,0,0,0,1}, // 3 -> 5
  {0,0,0,0,0,1}, // 4 -> 5
  {0,0,0,0,0,0}  // 5
};

// ------------------------------
// Visited Array
// ------------------------------
int visited[V] = {0};

// ------------------------------
// Stack
// ------------------------------
int stack[V];
int top = -1;

// ------------------------------
// Push into Stack
// ------------------------------
void push(int value) {

    stack[++top] = value;
}

// ------------------------------
// DFS Function
// ------------------------------
void DFS(int vertex) {

    visited[vertex] = 1;

    // Visit all adjacent vertices
    for (int i = 0; i < V; i++) {

        if (graph[vertex][i] == 1 && !visited[i]) {

            DFS(i);
        }
    }

    // Push after visiting children
    push(vertex);
}

// ------------------------------
// Topological Sort
// ------------------------------
void topologicalSort() {

    // Perform DFS for every vertex
    for (int i = 0; i < V; i++) {

        if (!visited[i]) {

            DFS(i);
        }
    }

    // Print stack in reverse order
    printf("Topological Order:\n\n");

    while (top != -1) {

        printf("%d ", stack[top--]);
    }

    printf("\n");
}

// ------------------------------
// Main Function
// ------------------------------
int main() {

    topologicalSort();

    return 0;
}
