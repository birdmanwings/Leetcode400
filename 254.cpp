#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        helper(n, res, {}, 2);
        return res;
    }

    void helper(int n, vector<vector<int>> &res, vector<int> out, int temp) {
        if (n == 1) {
            if (out.size() > 1) {
                res.push_back(out);
            }
        } else {
            for (int i = temp; i <= n; i++) {
                if ((n % i) == 0) {
                    out.push_back(i);
                    helper(n / i, res, out, i);
                    out.pop_back();
                }
            }
        }
    }
};

int main() {
    return 0;
}