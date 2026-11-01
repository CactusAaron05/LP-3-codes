//design by thinking that first queen is already placed
//use backtracking to place remaining queens

#include <iostream>
#include <vector>
using namespace std;

// Check whether a queen can be placed safely
bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check same column in previous rows
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Place queens using backtracking
bool solveNQueens(vector<vector<int>>& board, int row, int n) {
    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;

            if (solveNQueens(board, row + 1, n))
                return true;

            board[row][col] = 0; // Backtrack
        }
    }

    return false;
}

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;

    if (n <= 0) {
        cout << "Enter a positive number.\n";
        return 0;
    }

    vector<vector<int>> board(n, vector<int>(n, 0));

    // Place the first queen at row 0, column 0
    board[0][0] = 1;

    if (solveNQueens(board, 1, n)) {
        cout << "N-Queens Solution:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution with the first queen fixed at (1,1).\n";
    }

    return 0;
}