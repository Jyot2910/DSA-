#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<string>& board, int n) {
    // check column
    for(int i = 0; i < row; i++) {
        if(board[i][col] == 'Q') return false;
    }

    // upper-left diagonal
    int i = row - 1, j = col - 1;
    while(i >= 0 && j >= 0) {
        if(board[i][j] == 'Q') return false;
        i--; j--;
    }

    // upper-right diagonal
    i = row - 1; j = col + 1;
    while(i >= 0 && j < n) {
        if(board[i][j] == 'Q') return false;
        i--; j++;
    }

    return true;
}

void solve(int row, int n, vector<string>& board, int &count) {
    if(row == n) {
        count++;   // count solution
        return;
    }

    for(int col = 0; col < n; col++) {
        if(isSafe(row, col, board, n)) {
            board[row][col] = 'Q';

            solve(row + 1, n, board, count);

            board[row][col] = '.'; // backtrack
        }
    }
}

int main() {
    int n = 4;

    vector<string> board(n, string(n, '.'));
    int count = 0;

    solve(0, n, board, count);

    cout << "Total solutions: " << count << endl;

    return 0;
}