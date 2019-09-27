#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> out;
        combinationSum3DFS(k, n, res, out, 1);
        return res;
    }

    void combinationSum3DFS(int k, int n, vector<vector<int>> &res, vector<int> &out, int level) {
        if (n < 0) {
            return;
        } else if (n == 0 && out.size() == k) {
            res.push_back(out);
        }
        for (int i = level; i < 10; i++) {  //level用来记录从哪里开始
            out.push_back(i);
            combinationSum3DFS(k, n - i, res, out, i + 1);
            out.pop_back();
        }
    }
};

int main() {

    return 0;
}