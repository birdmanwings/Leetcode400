#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[0].size(); j++) {
                if (rooms[i][j] == 0) {
                    dfs(rooms, i, j, 0);
                }
            }
        }
    }

    void dfs(vector<vector<int>> &rooms, int i, int j, int val) {
        if (i < 0 || i >= rooms.size() || j < 0 || j >= rooms[0].size() || rooms[i][j] < val) {
            return;
        }
        rooms[i][j] = val;
        dfs(rooms, i + 1, j, val + 1);
        dfs(rooms, i - 1, j, val + 1);
        dfs(rooms, i, j + 1, val + 1);
        dfs(rooms, i, j - 1, val + 1);
    }
};

int main() {
    return 0;
}