//
// Created by bdwms on 2020/6/27.
//
#include "vector"

using namespace std;

class Solution {
 public:
  int findLengthOfLCIS(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    int res = 0, cnt = 1;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] < nums[i + 1]) {
        cnt++;
      } else {
        res = max(res, cnt);
        cnt = 1;
      }
    }
    res = max(res, cnt);
    return res;
  }
};