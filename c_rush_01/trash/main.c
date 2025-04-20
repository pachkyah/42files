#include <stdio.h>
#include <stdbool.h>

#define SIZE 4

// Function prototypes
bool isSafe(int board[SIZE][SIZE], int row, int col, int num);
bool checkVisibility(int board[SIZE][SIZE], int visibility[SIZE], int row, int col);
void printBoard(int board[SIZE][SIZE]);

// Stack structure for iterative backtracking
typedef struct {
    int board[SIZE][SIZE];
    int row;
    int col;
} StackState;

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

    // Stack for iterative backtracking
    StackState stack[sizeof(int)*(SIZE * SIZE + 2)];  // Maximum size of stack would be SIZE * SIZE
    int stackPointer = -1;

    // Initial state: Start at (0, 0)
    stack[++stackPointer] = (StackState){board, 0, 0};

    // Iterative backtracking
    while (stackPointer >= 0) {
        StackState currentState = stack[stackPointer];
        int row = currentState.row;
        int col = currentState.col;

        // Try placing numbers 1-4 in the current cell
        bool placed = false;
        for (int num = 1; num <= SIZE; num++) {
            if (isSafe(currentState.board, row, col, num)) {
                // Place the number and check visibility constraints
                currentState.board[row][col] = num;
                if (checkVisibility(currentState.board, visibility, row, col)) {
                    // Move to the next cell (next column, or next row if at end of column)
                    int nextRow = row;
                    int nextCol = col + 1;
                    if (nextCol == SIZE) {
                        nextCol = 0;
                        nextRow++;
                    }

                    // If we're done with the board, we have a solution
                    if (nextRow == SIZE) {
                        printf("Solution found!\n");
                        printBoard(currentState.board);
                        return 0;
                    }

                    // Push the next state onto the stack
                    stack[++stackPointer] = (StackState){{0}, nextRow, nextCol};
                    // Copy current board state to the stack's board
                    for (int i = 0; i < SIZE; i++) {
                        for (int j = 0; j < SIZE; j++) {
                            stack[stackPointer].board[i][j] = currentState.board[i][j];
                        }
                    }

                    placed = true;
                    break;  // Try the next number
                }
            }
        }

        // If we couldn't place any number, backtrack by popping the stack
        if (!placed) {
            stackPointer--;  // Backtrack
        }
    }

    printf("No solution exists!\n");
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
