#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100 // Maximum board size allowed

int queen_col[MAX]; // queen_col[row] = column index of queen in that row
int board_size;     // Number of queens and size of the chessboard (N x N)

// Function to check if a queen can be safely placed at the current position
int isSafe(int row)
{
    for (int prev_row = 1; prev_row < row; prev_row++)
    {
        // Check if there's a conflict:
        // - Same column: queen_col[prev_row] == queen_col[row]
        // - Same diagonal: absolute row and column differences are equal
        if (queen_col[prev_row] == queen_col[row] ||
            abs(prev_row - row) == abs(queen_col[prev_row] - queen_col[row]))
        {
            return 0; // Not safe
        }
    }
    return 1; // Safe position
}

// Function to solve the N-Queens problem using backtracking
void solveNQueens()
{
    int row = 1;           // Start from the first row
    queen_col[row] = 0;    // Initialize column position

    while (row != 0)       // Continue until all rows are processed or backtracked
    {
        queen_col[row]++;  // Try the next column in the current row

        // Try to find a valid column in the current row
        while (queen_col[row] <= board_size && !isSafe(row))
        {
            queen_col[row]++;
        }

        if (queen_col[row] <= board_size)
        {
            if (row == board_size)
            {
                // A complete valid solution is found
                printf("Solution: ");
                for (int i = 1; i <= board_size; i++)
                {
                    printf("(%d,%d) ", i, queen_col[i]); // Print queen positions
                }
                printf("\n");
            }
            else
            {
                // Move to the next row and reset column for that row
                row++;
                queen_col[row] = 0;
            }
        }
        else
        {
            // No valid column in current row, backtrack to the previous row
            row--;
        }
    }
}

int main()
{
    // Prompt user to enter number of queens
    printf("Enter the number of queens: ");
    scanf("%d", &board_size);

    // Validate input
    if (board_size < 1 || board_size > MAX)
    {
        printf("Invalid number of queens. Please enter between 1 and %d.\n", MAX);
        return 1;
    }

    // Solve and display all possible solutions
    printf("Solutions for %d-Queens problem:\n", board_size);
    solveNQueens();

    return 0;
}
