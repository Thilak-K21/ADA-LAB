#include <stdio.h>

#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int n, int W, int wt[], int val[]) {
    int F[MAX][MAX]; // DP table

    // Build table F[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                F[i][j] = 0;
            else if (wt[i - 1] <= j)
                F[i][j] = max(F[i - 1][j], val[i - 1] + F[i - 1][j - wt[i - 1]]);
            else
                F[i][j] = F[i - 1][j];
        }
    }

    // Maximum value that can be put in knapsack of capacity W
    printf("Maximum profit: %d\n", F[n][W]);

    // To print the selected items (optional)
    int res = F[n][W];
    int w = W;
    printf("Selected items (0-based indices): ");
    for (int i = n; i > 0 && res > 0; i--) {
        if (res == F[i - 1][w])
            continue; // item i-1 not included
        else {
            printf("%d ", i); // item i-1 included
            res -= val[i - 1];
            w -= wt[i - 1];
        }
    }
    printf("\n");
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];

    printf("Enter the profits of the items: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);

    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);

    knapsack(n, W, wt, val);

    return 0;
}
