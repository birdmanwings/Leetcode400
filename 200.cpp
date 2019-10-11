#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    numIslandsDFS(grid, visited, i, j);
                    res++;
                }
            }
        }
        return res;
    }

    void numIslandsDFS(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j) {
        if (i < 0 || i >= grid.size()) {
            return;
        }
        if (j < 0 || j >= grid[0].size()) {
            return;
        }
        if (grid[i][j] != '1' || visited[i][j]) {
            return;
        }
        visited[i][j]=true;
        numIslandsDFS(grid, visited, i + 1, j);
        numIslandsDFS(grid, visited, i - 1, j);
        numIslandsDFS(grid, visited, i, j + 1);
        numIslandsDFS(grid, visited, i, j - 1);
    }
};

int main() {
    return 0;
}