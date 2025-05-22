#include <stdio.h>

#define MAX 100

int visited[MAX], res[MAX], j = -1;  // For DFS method
int indegree[MAX], stack[MAX], top = -1;  // For Source Removal method

void dfs(int u, int adj[MAX][MAX], int n) {
    visited[u] = 1;
    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1 && visited[v] == 0) {
            dfs(v, adj, n);
        }
    }
    j++;
    res[j] = u; // Store node after exploring all its neighbors
}

void topologicalSortDFS(int adj[MAX][MAX], int n) {
    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    j = -1; // Reset result index

    // Perform DFS from all unvisited nodes
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(i, adj, n);
        }
    }

    printf("Topological Sort (DFS Method):\n");
    for (int i = j; i >= 0; i--) {
        printf("%d ", res[i]);
    }
    printf("\n");
}

void topologicalSortSourceRemoval(int adj[MAX][MAX], int n) {
    top = -1;
    int result[MAX], t = 0;

    // Calculate in-degree of each vertex
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += adj[i][j];
        }
        indegree[j] = sum;
    }

    // Push vertices with in-degree 0 to stack
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            stack[++top] = i;
        }
    }

    while (top != -1) {
        int u = stack[top--];
        result[t++] = u;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    stack[++top] = v;
                }
            }
        }
    }

    // Check if topological sorting was successful (no cycles)
    if (t != n) {
        printf("The graph has a cycle. Topological sort not possible.\n");
    } else {
        printf("Topological Sort (Source Removal Method):\n");
        for (int i = 0; i < t; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use 1 for edge, 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("\n--- Performing Topological Sorts ---\n");
    topologicalSortDFS(adj, n);
    topologicalSortSourceRemoval(adj, n);

    return 0;
}
