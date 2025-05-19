#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int w[MAX], x[MAX];
int n, d;

// Function to sort weights in increasing order
void sortWeights() {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (w[i] > w[j]) {
                int temp = w[i];
                w[i] = w[j];
                w[j] = temp;
            }
        }
    }
}

// Recursive function to find subsets that sum to d
void SumofSub(int cs, int k, int r) {
    if (k > n) return; // Base case: if k exceeds bounds, stop

    x[k] = 1; // Try including w[k]

    if (cs + w[k] == d) {
        // Valid subset found
        printf("Subset found: ");
        for (int i = 1; i <= k; i++) {
            if (x[i] == 1)
                printf("%d ", w[i]);
        }
        printf("\n");
    }
    else if (k < n && cs + w[k] + w[k + 1] <= d) {
        SumofSub(cs + w[k], k + 1, r - w[k]);
    }

    if (k < n && cs + r - w[k] >= d && cs + w[k + 1] <= d) {
        x[k] = 0; // Try excluding w[k]
        SumofSub(cs, k + 1, r - w[k]);
    }
}

int main() {
    int total = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the target sum d: ");
    scanf("%d", &d);

    printf("Enter the weights: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
        total += w[i];
    }

    sortWeights(); // Important: Sort the weights before using the algorithm

    if (w[1] > d || total < d) {
        printf("No subsets possible.\n");
        return 0;
    }

    // Initial call
    SumofSub(0, 1, total);

    return 0;
}
