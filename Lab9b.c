#include <stdio.h>
#define MAX 5 // Maximum number of vertices in the graph

// Function to perform DFS traversal
void dfs(int adj[][MAX], int visited[], int start) {
    int s[MAX], top = -1, i;

    // Push the starting vertex onto the stack and mark it as visited
    s[++top] = start;
    visited[start] = 1;

    // Perform DFS traversal
    while (top != -1) {
        // Pop the top element from the stack
        start = s[top--];
        printf("%c -> ", start + 'A'); // Print the current vertex

        // Traverse all neighbors of the current vertex
        for (i = 0; i < MAX; i++) {
            if (adj[start][i] && visited[i] == 0) { // If there's an edge and the vertex is unvisited
                s[++top] = i;   // Push the vertex onto the stack
                visited[i] = 1; // Mark it as visited
            }
        }
    }
}

int isConnected(int adj[][MAX]) {
    int visited[MAX] = {0}; // Initialize all vertices as unvisited
    int i;

    // Perform DFS starting from vertex 0
    dfs(adj, visited, 0);

    // Check if all vertices are visited
    for (i = 0; i < MAX; i++) {
        if (visited[i] == 0) {
            return 0; // Graph is not connected
        }
    }
    return 1; // Graph is connected
}

int main() {
    int adj[MAX][MAX], i, j;

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (5x5):\n");
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Check if the graph is connected
    if (isConnected(adj)) {
        printf("\nThe graph is connected.\n");
    } else {
        printf("\nThe graph is not connected.\n");
    }

    return 0;
}
