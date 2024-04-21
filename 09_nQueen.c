#include <stdio.h>
#include <stdbool.h>

#define N 5 // Default board size

// Function to check if it's safe to place a queen at board[row][col]
bool isPlaceSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check left side of current row
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve N Queens problem
bool solveNQueens(int board[N][N], int col) {
    int i;
    // If all queens are placed, return true
    if (col >= N)
        return true;

    // Try placing a queen in all rows of the current column
    for ( i = 0; i < N; i++) {
        // Check if queen can be placed in board[i][col]
        if (isPlaceSafe(board, i, col)) {
            // Place queen at board[i][col]
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueens(board, col + 1))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution, remove queen from board[i][col]
            board[i][col] = 0; // Backtrack
        }
    }
    // If queen cannot be placed in any row of this column, return false
    return false;
}

// Function to print the solution matrix
void printSolutionMatrix(int board[N][N]) {
    int i,j;
    for ( i = 0; i < N; i++) {
        for ( j = 0; j < N; j++) {
            if (board[i][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

// Function to solve N Queens problem
void solveNQueensProblem() {
    int board[N][N] = {{0}}; // Initialize board with all 0s

    // Start with column 0
    if (solveNQueens(board, 0) == false) {
        printf("Solution does not exist\n");
        return;
    }

    // Solution found, print the solution
    printf("Solution for %d Queens problem:\n", N);
    printSolutionMatrix(board);
}

// Main function
int main() {
    solveNQueensProblem();
    return 0;
}
