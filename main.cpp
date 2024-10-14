#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Check if placing num in board[row][col] is valid
bool isValid(vector<vector<int>>& board, int row, int col, int num) {
    // Check the row

    for (int i = 0; i < 9; i++) {
            if (board[row][i] == num) return false;
        }
    

    // Check the column
    for (int i = 0; i < 9 ; i++) {
            if (board[i][col] == num) return false;
        }
    

    // Check the 3x3 sub-grid
    if (row == 0 || row == 1 || row == 2){
        if (col == 0 || col == 1 || col == 2){
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == num) return false;
                }
            }

        }

        else if (col == 3 || col == 4 || col == 5){
            
             for (int i = 0; i < 3; i++) {
                for (int j = 3; j < 6; j++) {
                    if (board[i][j] == num) return false;
                }
            }

        } 

        else if (col == 6 || col == 7 || col == 8){
            
             for (int i = 0; i < 3; i++) {
                for (int j = 6; j < 9; j++) {
                    if (board[i][j] == num) return false;
                }
            }

        }

    }
    else if (row == 3 || row == 4 || row == 5){
      if (col == 0 || col == 1 || col == 2){
            for (int i = 3; i < 6; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == num) return false;
                }
            }

        }

        else if (col == 3 || col == 4 || col == 5){
            
             for (int i = 3; i < 6; i++) {
                for (int j = 3; j < 6; j++) {
                    if (board[i][j] == num) return false;
                }
            }

        } 

        else if (col == 6 || col == 7 || col == 8){
            
             for (int i = 3; i < 6; i++) {
                for (int j = 6; j < 9; j++) {
                    if (board[i][j] == num) return false;
                }
            }

        }

    }

    else if (row == 6 || row == 7 || row == 8){
        if (col == 0 || col == 1 || col == 2){
            for (int i = 6; i < 9; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == num) return false;
                }
            }

        }

        else if (col == 3 || col == 4 || col == 5){
            
             for (int i = 6; i < 9; i++) {
                for (int j = 3; j < 6; j++) {
                    if (board[i][j] == num) return false;
                }
            }

        } 

        else if (col == 6 || col == 7 || col == 8){
            
             for (int i = 6; i < 9; i++) {
                for (int j = 6; j < 9; j++) {
                    if (board[i][j] == num) return false;
                }
            }

        }

    }

    //board[row][col] = num;

    return true;
}

// Find the next empty cell (represented by 0)
// findEmpty() picks out the values of row,col by locating the first empty square
bool findEmpty(const vector<vector<int>>& board, int& row, int& col) {
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                //cout << row << " " << col;
                return true;
            }
        }
    }
    return false;  // No empty cells left
}

// BFS Sudoku Solver
bool bfsSudokuSolver(vector<vector<int>>& board) {
    // Define a queue to store boards (state of the Sudoku board)
    queue<vector<vector<int>>> q;
    q.push(board);

    int row = 0;
    int col = 0;

    while (!q.empty()) {

        vector<vector<int>> currentBoard = q.front();
        q.pop();

        if (!findEmpty(currentBoard, row, col)){
            board = currentBoard; // update board with the solution board
            return true;

        }

        //cout << row << " " << col;

         //Check If there's no empty cell, it means we found a solution, and we're done! :)
         //If that's the case update "board" and exit
          
        for (int num = 1; num <= 9; num++) {
            if (isValid(currentBoard, row, col, num)) {
                vector<vector<int>> newBoard = currentBoard;
                newBoard[row][col] = num;
                q.push(newBoard);
            }
        }
        // Try placing numbers 1-9 in the empty cell
        // use isValid() to determine if any of those numbers (potentially) work
        // if they do, push the new board to the queue and keep going
        // numbers that pass isValid() but do not work, will eventually find a logical contridiction 
        // and disappear from the solution list
    }

    return false;  // No solution found
}

// Utility function to print the board
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Initialize a Sudoku board with some empty cells (represented by 0)
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Initial Board:" << endl;
    printBoard(board);

    if (bfsSudokuSolver(board)) {
        cout << "\nSolved Board:" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists for the given Sudoku puzzle." << endl;
    }

    return 0;
}