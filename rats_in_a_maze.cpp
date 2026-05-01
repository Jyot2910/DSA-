#include <iostream>
#include <vector>
using namespace std;

void solve(int i, int j, vector<vector<int>>& maze, int n,
           vector<string>& ans, string path,
           vector<vector<int>>& vis) {

    // destination reached
    if(i == n-1 && j == n-1) {
        ans.push_back(path);
        return;
    }

    // mark current cell visited
    vis[i][j] = 1;

    // Down
    if(i+1 < n && maze[i+1][j] == 1 && !vis[i+1][j]) {
        solve(i+1, j, maze, n, ans, path + 'D', vis);
    }

    // Left
    if(j-1 >= 0 && maze[i][j-1] == 1 && !vis[i][j-1]) {
        solve(i, j-1, maze, n, ans, path + 'L', vis);
    }

    // Right
    if(j+1 < n && maze[i][j+1] == 1 && !vis[i][j+1]) {
        solve(i, j+1, maze, n, ans, path + 'R', vis);
    }

    // Up
    if(i-1 >= 0 && maze[i-1][j] == 1 && !vis[i-1][j]) {
        solve(i-1, j, maze, n, ans, path + 'U', vis);
    }

    //  backtrack
    vis[i][j] = 0;
}

int main() {
    vector<vector<int>> maze = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };

    int n = maze.size();

    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));

    if(maze[0][0] == 1) {
        solve(0, 0, maze, n, ans, "", vis);
    }

    cout << "Paths:\n";
    for(auto &p : ans) {
        cout << p << endl;
    }

    return 0;
}