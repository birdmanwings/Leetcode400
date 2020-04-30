#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <set>

using namespace std;

/*
 * 先排序，固定最左边的，再利用双指针来扫描，注意跳过重复的，然后有一些特殊情况可以直接跳
 * 时间复杂度，排序O(nlogn),然后fix的数扫描是O(n)再乘上一个双指针的O(n)，所以最后是,O(n^2)
 * 空间复杂度，res,O(1)
 */
//class Solution {
// public:
//  vector<vector<int>> threeSum(vector<int> &nums) {
//    vector<vector<int>> res;
//    sort(nums.begin(), nums.end());
//    if (nums.empty() || nums.back() < 0 || nums.front() > 0) {
//      return {};
//    }
//    for (int i = 0; i < nums.size(); i++) {
//      if (nums[i] > 0) {  // 大于0的时候后面的两个肯定>0
//        break;
//      }
//      if (i > 0 && nums[i] == nums[i - 1]) {  // 跳过重复的fix的树木
//        continue;
//      }
//      int target = 0 - nums[i];
//      int left = i + 1, right = nums.size() - 1;
//      while (left < right) {
//        if (target == nums[left] + nums[right]) {
//          res.push_back({nums[i], nums[left], nums[right]});
//          while (left < right && nums[left] == nums[left + 1]) left++;
//          while (left < right && nums[right] == nums[right - 1]) right--;
//          ++left;
//          --right;
//        } else if (target < nums[left] + nums[right]) {  // target较小的时候需要让右边的下表剑侠
//          --right;
//        } else {
//          ++left;
//        }
//      }
//    }
//    return res;
//  }
//};


/*
 * 用set来避免重复
 */
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> res;
    sort(nums.begin(), nums.end());
    if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
    for (int k = 0; k < nums.size(); ++k) {
      if (nums[k] > 0) break;
      int target = 0 - nums[k];
      int i = k + 1, j = nums.size() - 1;
      while (i < j) {
        if (nums[i] + nums[j] == target) {
          res.insert({nums[k], nums[i], nums[j]});
          while (i < j && nums[i] == nums[i + 1]) ++i;
          while (i < j && nums[j] == nums[j - 1]) --j;
          ++i; --j;
        } else if (nums[i] + nums[j] < target) ++i;
        else --j;
      }
    }
    return vector<vector<int>>(res.begin(), res.end());
  }
};

int main() {

  return 0;
}