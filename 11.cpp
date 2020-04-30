//
// Created by bdwms on 2020/4/29.
//
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 时间复杂度，双指针扫一遍O(n)
 * 空间复杂度，O(1)
 */
//class Solution {
// public:
//  int maxArea(vector<int> &height) {
//    int res = 0, left = 0, right = height.size() - 1;
//    while (left < right) {
//      res = max(res, min(height[right], height[left]) * (right - left));
//      height[left] < height[right] ? ++left : --right;
//    }
//    return res;
//  }
//};

/*
 * 加入一个判断，当相等时直接跳过
 */
class Solution {
 public:
  int maxArea(vector<int> &height) {
    int res = 0, left = 0, right = height.size() - 1, h;
    while (left < right) {
      h = min(height[left], height[right]);
      res = max(res, h * (right - left));
      while (left < right && h == height[left]) left++;
      while (left < right && h == height[right]) right--;
    }
    return res;
  }
};