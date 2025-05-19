#include <stdio.h>

#define MAX 10  // Maximum number of vertices

void warshall(int n, int A[n][n]) {
    int R[n][n];

    // Initialize R to be the same as A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            R[i][j] = A[i][j];
        }
    }

    // Warshall's Algorithm: Compute the transitive closure
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                R[i][j] = R[i][j] || (R[i][k] && R[k][j]);
            }
        }
    }

    // Output the transitive closure matrix R
    printf("Transitive Closure Matrix (R):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    // Read the number of vertices
    printf("Enter the number of vertices (n): ");
    scanf("%d", &n);

    int A[n][n];

    // Read the adjacency matrix
    printf("Enter the adjacency matrix (A):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Compute the transitive closure using Warshall's algorithm
    warshall(n, A);

    return 0;
}
