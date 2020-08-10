//
// Created by bdwms on 2020/7/10.
//
#include <vector>

using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    int closest = nums[0] + nums[1] + nums[2];
    int diff = abs(closest - target);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
      int left = i + 1, right = nums.size() - 1;
      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        int tempdiff = abs(sum - target);
        if (diff > tempdiff) {
          diff = tempdiff;
          closest = sum;
        }
        if (sum < target) {
          left++;
        } else {
          right--;
        }
      }
    }
    return closest;
  }
};