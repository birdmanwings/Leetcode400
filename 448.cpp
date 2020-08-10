//
// Created by bdwms on 2020/7/25.
//
#include <vector>

using namespace std;

/*
 * 把指定位置的数字变负来确定这个下标存在数字
 */
class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      int idx = abs(nums[i]) - 1;
      nums[idx] = (nums[idx] > 0) ? -nums[idx] : nums[idx];
    }
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        res.push_back(i + 1);
      }
    }
    return res;
  }
};
