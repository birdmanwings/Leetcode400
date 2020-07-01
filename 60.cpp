//
// Created by bdwms on 2020/6/27.
//
#include "string"
#include "vector"

using namespace std;

/*
 * 总的来说就是找规律类似
 */
class Solution {
 public:
  string getPermutation(int n, int k) {
    string res;
    string nums = "123456789";
    vector<int> f(n, 1);  // 存放对应下标的阶乘
    for (int i = 1; i < n; i++) {
      f[i] = f[i - 1] * i;
    }
    --k;
    for (int i = n; i >= 1; i--) {
      int j = k / f[i - 1];
      k %= f[i - 1];
      res.push_back(nums[j]);
      nums.erase(j, 1);
    }
    return res;
  }
};