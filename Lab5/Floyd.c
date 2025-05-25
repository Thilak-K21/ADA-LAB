#include <stdio.h>

#define MAX 100
#define INF 99999

void floydWarshall(int n, int graph[MAX][MAX]) {
    int dist[MAX][MAX];

    // Initialize distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print result
    printf("All-Pairs Shortest Path Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter the adjacency matrix (enter 0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int value;
            if (scanf("%d", &value) != 1) {
                printf("Invalid input.\n");
                return 1;
            }
            graph[i][j] = (i != j && value == 0) ? INF : value;
        }
    }

    floydWarshall(n, graph);

    return 0;
}
