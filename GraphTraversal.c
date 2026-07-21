#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];

int vertices;

// Breadth First Search (BFS)
void bfs(int start) {

    int front = 0;
    int rear = 0;

    for(int i = 0; i < vertices; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS Traversal: ");

    while(front < rear) {

        int current = queue[front++];

        printf("%d ", current);

        for(int i = 0; i < vertices; i++) {

            if(graph[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }

        }

    }

    printf("\n");
}

// Depth First Search (DFS)
void dfs(int vertex) {

    visited[vertex] = 1;

    printf("%d ", vertex);

    for(int i = 0; i < vertices; i++) {

        if(graph[vertex][i] == 1 && visited[i] == 0) {
            dfs(i);
        }

    }

}

int main() {

    int edges;
    int source, destination;
    int start;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize graph
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter each edge (source destination):\n");

    for(int i = 0; i < edges; i++) {

        scanf("%d %d", &source, &destination);

        graph[source][destination] = 1;
        graph[destination][source] = 1;

    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    bfs(start);

    for(int i = 0; i < vertices; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    dfs(start);

    printf("\n");

    return 0;
}
