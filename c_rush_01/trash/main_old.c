#include <stdio.h>
#include <stdbool.h>

#define SIZE 4

// Function prototypes
bool isSafe(int board[SIZE][SIZE], int row, int col, int num);
bool checkVisibility(int board[SIZE][SIZE], int visibility[SIZE], int row, int col);
bool solvePuzzle(int board[SIZE][SIZE], int visibility[SIZE], int row, int col);
void printBoard(int board[SIZE][SIZE]);

// Main function
int main() {
    int board[SIZE][SIZE] = {0}; // Initialize a 4x4 grid (0 means empty)
    
    // Example visibility constraints (flattened array with 4 parts)
    // [top(0-3), bottom(4-7), left(8-11), right(12-15)]
    int visibility[SIZE * 4] = {
        4, 3, 2, 1,  // Top view constraints
        1, 2, 2, 2,  // Bottom view constraints
        4, 3, 2, 1,  // Left view constraints
        1, 2, 2, 2   // Right view constraints
    };

    if (solvePuzzle(board, visibility, 0, 0)) {
        printf("Solution found!\n");
        printBoard(board);
    } else {
        printf("No solution exists!\n");
    }

    return 0;
}

// Function to check if placing a number is valid
bool isSafe(int board[SIZE][SIZE], int row, int col, int num) {
    int i = 0;
    
    // Check row for duplicates
    while (i < SIZE) {
        if (board[row][i] == num) {
            return false;
        }
        i++;
    }

    i = 0;
    // Check column for duplicates
    while (i < SIZE) {
        if (board[i][col] == num) {
            return false;
        }
        i++;
    }
    
    return true;
}

// Function to check visibility constraints
bool checkVisibility(int board[SIZE][SIZE], int visibility[SIZE], int row, int col) {
    // Check top view for column `col` if it's the last row
    if (row == SIZE - 1) {  // If we've filled the entire column
        int visibleCount = 0, highest = 0;
        int topVisibility = visibility[col];  // Visibility constraint from the top (first 4 items)
        int i = 0;
        while (i < SIZE) {
            if (board[i][col] > highest) {
                visibleCount++;
                highest = board[i][col];
            }
            i++;
        }
        if (visibleCount != topVisibility) {
            return false;
        }
    }

    // Check bottom view for column `col` if it's the first row (we should verify bottom view when filling the row from top to bottom)
    if (row == 0) {  // If we've filled the first row, check the bottom view
        int visibleCount = 0, highest = 0;
        int bottomVisibility = visibility[SIZE + col];  // Visibility constraint from the bottom (next 4 items)
        int i = SIZE - 1;
        while (i >= 0) {
            if (board[i][col] > highest) {
                visibleCount++;
                highest = board[i][col];
            }
            i--;
        }
        if (visibleCount != bottomVisibility) {
            return false;
        }
    }

    // Check left view for row `row` if it's the last column
    if (col == SIZE - 1) {  // If we've filled the entire row
        int visibleCount = 0, highest = 0;
        int leftVisibility = visibility[SIZE * 2 + row];  // Visibility constraint from the left (next 4 items after top & bottom)
        int i = 0;
        while (i < SIZE) {
            if (board[row][i] > highest) {
                visibleCount++;
                highest = board[row][i];
            }
            i++;
        }
        if (visibleCount != leftVisibility) {
            return false;
        }
    }

    // Check right view for row `row` if it's the first column
    if (col == 0) {  // If we've filled the first column, check the right view
        int visibleCount = 0, highest = 0;
        int rightVisibility = visibility[SIZE * 3 + row];  // Visibility constraint from the right (last 4 items)
        int i = SIZE - 1;
        while (i >= 0) {
            if (board[row][i] > highest) {
                visibleCount++;
                highest = board[row][i];
            }
            i--;
        }
        if (visibleCount != rightVisibility) {
            return false;
        }
    }

    return true;
}


// Backtracking function to solve the puzzle
bool solvePuzzle(int board[SIZE][SIZE], int visibility[SIZE], int row, int col) {
    // If we have filled all columns in the row, move to the next row
    if (col == SIZE) {
        col = 0;
        row++;
        if (row == SIZE) {
            return true; // Puzzle solved
        }
    }

    // Skip cells that are already filled
    if (board[row][col] != 0) {
        return solvePuzzle(board, visibility, row, col + 1);
    }

    // Try placing numbers 1-4
    int num = 1;
    while (num <= SIZE) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (checkVisibility(board, visibility, row, col)) {
                if (solvePuzzle(board, visibility, row, col + 1)) {
                    return true;
                }
            }
            board[row][col] = 0; // Backtrack
        }
        num++;
    }

    return false; // No solution found for this cell
}

// Function to print the board
void printBoard(int board[SIZE][SIZE]) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            printf("%d ", board[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}
