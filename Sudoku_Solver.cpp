#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>>& board, int row, int col, char num) {
    // check row
    for(int j = 0; j < 9; j++) {
        if(board[row][j] == num) return false;
    }

    // check column
    for(int i = 0; i < 9; i++) {
        if(board[i][col] == num) return false;
    }

    // check 3x3 box
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

bool helper(vector<vector<char>>& board, int row, int col) {
    // base case
    if(row == 9) return true;

    int nextRow = row, nextCol = col + 1;

    if(nextCol == 9) {
        nextRow = row + 1;
        nextCol = 0;
    }

    // skip filled cell
    if(board[row][col] != '.') {
        return helper(board, nextRow, nextCol);
    }

    // try digits
    for(char dig = '1'; dig <= '9'; dig++) {
        if(isSafe(board, row, col, dig)) {
            board[row][col] = dig;

            if(helper(board, nextRow, nextCol)) return true;

            board[row][col] = '.'; // backtrack
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    helper(board, 0, 0);

    cout << "Solved Sudoku:\n";
    for(auto& row : board) {
        for(auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}