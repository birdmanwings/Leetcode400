#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            return vector<vector<int>>(1, vector<int>());
        }
        vector<vector<int>> res;
        int temp = nums[0];
        nums.erase(nums.begin());
        vector<vector<int>> words = permute(nums);
        for (auto &a : words) {
            for (int i = 0; i <= a.size(); i++) {
                a.insert(a.begin() + i, temp);
                res.push_back(a);
                a.erase(a.begin() + i);
            }
        }
        return res;
    }
};

int main() {

    return 0;
}