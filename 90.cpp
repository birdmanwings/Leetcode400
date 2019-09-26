#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        if (nums.empty()) {
            return {};
        }
        vector<vector<int>> res(1); //初始化了一个空集
        sort(nums.begin(), nums.end());
        int last = nums[0];
        int size = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (last != nums[i]) {
                last = nums[i];
                size = res.size();  //相等时size存储的是上次的res数量
            }
            int newSize = res.size();
            for (int j = newSize - size; j < newSize; j++) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};

int main() {

    return 0;
}