#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        set<vector<int>> res;
        permute(nums, 0, res);
        return vector<vector<int>>(res.begin(), res.end());
    }

    void permute(vector<int> &nums, int start, set<vector<int>> &res) {
        if (start >= nums.size()) {
            res.insert(nums);
        }
        for (int i = start; i < nums.size(); i++) {
            if (i != start && nums[i] == nums[start]) {
                continue;
            }
            swap(nums[i], nums[start]);
            permute(nums, start + 1, res);
            swap(nums[i], nums[start]);
        }
    }
};

int main() {

    return 0;
}