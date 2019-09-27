#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        sort(candidates.begin(), candidates.end());
        combinationSumDFS(candidates, target, res, 0, out);
        return res;
    }

    void combinationSumDFS(vector<int> &candidates, int target, vector<vector<int>> &res, int start, vector<int> out) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            res.push_back(out);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            out.push_back(candidates[i]);
            combinationSumDFS(candidates, target - candidates[i], res, i, out);
            out.pop_back();
        }
    }
};

int main() {

    return 0;
}