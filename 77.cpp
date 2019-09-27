#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> out;
        helper(n, k, 1, res, out);
        return res;
    }

    void helper(int n, int k, int level, vector<vector<int>> &res, vector<int> &out) {
        if (out.size() == k) {
            res.push_back(out);
            return;
        }
        for (int i = level; i <= n; i++) {
            out.push_back(i);
            helper(n, k, i + 1, res, out);
            out.pop_back();
        }
    }
};

int main() {

    return 0;
}