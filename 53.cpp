//
// Created by bdwms on 2020/7/4.
//
#include "vector"

using namespace std;

/*
 * 只要curSum是大于0的就说明它是有用的，继续往上面累加，否则的话就从当前数字重新开始
 */
//class Solution {
// public:
//  int maxSubArray(vector<int> &nums) {
//    int res = 0, curSum = 0;
//    for (auto n:nums) {
//      curSum = max(curSum + n, n);
//      res = max(res, curSum);
//    }
//    return res;
//  }
//};

/*
 * 分治法，求左右两侧的最大子串和从中间往两边遍历的最大子串
 */
class Solution {
 public:
  int maxSubArray(vector<int> &nums) {
    if (nums.empty()) return 0;
    return helper(nums, 0, (int) nums.size() - 1);
  }
  int helper(vector<int> &nums, int left, int right) {
    if (left >= right) return nums[left];
    int mid = left + (right - left) / 2;
    int lmax = helper(nums, left, mid - 1);
    int rmax = helper(nums, mid + 1, right);
    int mmax = nums[mid], t = mmax;
    for (int i = mid - 1; i >= left; --i) {
      t += nums[i];
      mmax = max(mmax, t);
    }
    t = mmax;
    for (int i = mid + 1; i <= right; ++i) {
      t += nums[i];
      mmax = max(mmax, t);
    }
    return max(mmax, max(lmax, rmax));
  }
};
