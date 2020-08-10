//
// Created by bdwms on 2020/7/25.
//
#include <vector>

using namespace std;

/*
 * 排序比较不同
 */
//class Solution {
// public:
//  int findUnsortedSubarray(vector<int>& nums) {
//    int n = nums.size(), i = 0, j = n - 1;
//    vector<int> t = nums;
//    sort(t.begin(), t.end());
//    while (i < n && nums[i] == t[i]) ++i;
//    while (j > i && nums[j] == t[j]) --j;
//    return j - i + 1;
//  }
//};


/*
 * 从前往后遍历找到最高峰顶应该在位置坐标，
 * 从后往前遍历找到最低峰应该在的位置坐标，
 * 那么中间的就是无序的
 */
class Solution {
 public:
  int findUnsortedSubarray(vector<int> &nums) {
    int n = nums.size(), end = -2, start = -1;
    int mx = nums[0], mn = nums[n - 1];
    for (int i = 1; i < n; i++) {
      mx = max(mx, nums[i]);
      mn = min(mn, nums[n - i - 1]);
      if (mx > nums[i]) end = i;
      if (mn < nums[n - 1 - i]) start = n - 1 - i;
    }
    return end - start + 1;
  }
};