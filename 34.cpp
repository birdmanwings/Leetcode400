#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * 这篇文章把二分搜索讲的很清除https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/er-fen-cha-zhao-suan-fa-xi-jie-xiang-jie-by-labula/
 * 时间复杂度O(logn)
 * 空间复杂度O(1)
 */
class Solution {
 private:
  int findLowerBound(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] == target) { // 关键在这里，我们找到target值时候需要先缩小右边界，才能保证返回小的下标
        right = mid - 1;
      }
    }
    if (left >= nums.size() || nums[left] != target) { // 注意边界情况，如果target过大的时候,left可能存在越界的情况，其他情况是不存在target
      return -1;
    }
    return left;
  }

  int findUpBound(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] == target) {
        left = mid + 1;
      }
    }
    if (right < 0 || nums[right] != target) { // 同样注意边界情况
      return -1;
    }
    return right;  // 其实这里返回left和right都一样因为跳出条件为left==right的时候
  }

 public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int size = nums.size();
    if (size == 0) {
      return {-1, -1};
    }
    int num1 = findLowerBound(nums, target);

    if (num1 == -1) {
      return {-1, -1};
    }
    int num2 = findUpBound(nums, target);
    return {num1, num2};
  }
};

int main() {

  return 0;
}