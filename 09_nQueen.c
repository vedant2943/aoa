#include <stdio.h>

#define N 100 // Maximum board size

// Function to check if it's safe to place a queen at board[row][col]
int isPlaceSafe(int board[][N], int row, int col, int size) {
    int i, j;

    // Check left side of current row
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Check lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < size; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

// Recursive function to solve N Queens problem
int solveNQueens(int board[][N], int col, int size) {
    int i;
    // If all queens are placed, return true
    if (col >= size)
        return 1;

    // Try placing a queen in all rows of the current column
    for ( i = 0; i < size; i++) {
        // Check if queen can be placed in board[i][col]
        if (isPlaceSafe(board, i, col, size)) {
            // Place queen at board[i][col]
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueens(board, col + 1, size))
                return 1;

            // If placing queen in board[i][col] doesn't lead to a solution, remove queen from board[i][col]
            board[i][col] = 0; // Backtrack
        }
    }
    // If queen cannot be placed in any row of this column, return false
    return 0;
}

// Function to print the solution matrix
void printSolutionMatrix(int board[][N], int size) {
    int i,j;
    for ( i = 0; i < size; i++) {
        for ( j = 0; j < size; j++) {
            if (board[i][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

// Function to solve N Queens problem
void solveNQueensProblem(int size) {
    int board[N][N] = {{0}}; // Initialize board with all 0s

    // Start with column 0
    if (solveNQueens(board, 0, size) == 0) {
        printf("Solution does not exist\n");
        return;
    }

    // Solution found, print the solution
    printf("Solution for %d Queens problem:\n", size);
    printSolutionMatrix(board, size);
}

// Main function
int main() {
    int size;
    printf("Enter the size of the chessboard: ");
    scanf("%d", &size);
    
    solveNQueensProblem(size);
    return 0;
}
