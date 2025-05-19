#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

int x[MAX]; // x[k] stores the column position of queen in row k
int n;      // Number of queens (and size of board)

// Function to check whether the kth queen can be placed in column x[k]
int place(int k) {
    for (int i = 1; i < k; i++) {
        if (x[i] == x[k] || abs(i - k) == abs(x[i] - x[k]))
            return 0; // Conflict in column or diagonal
    }
    return 1; // No conflict
}

// Function to solve the N-Queens problem
void nQueens(int n) {
    int k = 1;
    x[k] = 0; // Start with column 0 (will increment to 1 in loop)

    while (k != 0) {
        x[k] += 1; // Try next column in current row

        // Try placing queen in a valid column
        while (x[k] <= n && !place(k)) {
            x[k] += 1;
        }

        if (x[k] <= n) {
            if (k == n) {
                // Solution found, print it
                printf("Solution: ");
                for (int i = 1; i <= n; i++) {
                    printf("(%d,%d) ", i, x[i]);
                }
                printf("\n");
            } else {
                k++;
                x[k] = 0; // Initialize next queen
            }
        } else {
            k--; // Backtrack
        }
    }
}

// Main function
int main() {
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of queens. Please enter between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Solutions for %d-Queens problem:\n", n);
    nQueens(n);

    return 0;
}

