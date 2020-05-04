#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
 * 这一题只能用一次数字
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        sort(candidates.begin(), candidates.end());
        combinationSum2DFS(candidates, target, 0, res, out);
        return res;
    }

    void
    combinationSum2DFS(vector<int> &candidates, int target, int start, vector<vector<int>> &res, vector<int> &out) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            res.push_back(out);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {  // 跳过重复的数字
                continue;
            }
            out.push_back(candidates[i]);
            combinationSum2DFS(candidates, target - candidates[i], i + 1, res, out);  // 注意加1来直接跳过重复
            out.pop_back();
        }
    }
};

int main() {

    return 0;
}