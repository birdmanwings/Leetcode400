//
// Created by bdwms on 2020/7/25.
//
#include <vector>

using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int> &nums) {
    for (int i = 0, j = 0; i < nums.size(); i++) {
      if (nums[i]) {
        swap(nums[i], nums[j++]);
      }
    }
  }
};