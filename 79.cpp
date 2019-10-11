#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty() || board[0].empty()) {
            return false;
        }
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (search(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }

    bool search(vector<vector<char>> &board, string word, int idx, int i, int j) {  //idx表示已经匹配的字母数量
        if (idx == word.size()) {   //终止条件
            return true;
        }
        int m = board.size(), n = board[i].size();
        if (i < 0 || j < 0 || i > m || j > m || board[i][j] != word[idx]) {
            return false;
        }
        char tmp = board[i][j];
        board[i][j] = '#';
        bool res = search(board, word, idx + 1, i - 1, j) || search(board, word, idx + 1, i + 1, j) ||
                   search(board, word, idx + 1, i, j + 1) || search(board, word, idx + 1, i, j - 1);
        board[i][j]=tmp;
        return res;
    }
};

int main() {

    return 0;
}