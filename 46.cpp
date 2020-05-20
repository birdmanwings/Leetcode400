#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//    vector<vector<int>> permute(vector<int>& nums) {
//        if (nums.empty()) {
//            return vector<vector<int>>(1, vector<int>());
//        }
//        vector<vector<int>> res;
//        int temp = nums[0];
//        nums.erase(nums.begin());
//        vector<vector<int>> words = permute(nums);
//        for (auto &a : words) {
//            for (int i = 0; i <= a.size(); i++) {
//                a.insert(a.begin() + i, temp);
//                res.push_back(a);
//                a.erase(a.begin() + i);
//            }
//        }
//        return res;
//    }
//};

/*
 * 用递归的方法
 * 时间复杂度O()
 */
//class Solution {
// public:
//  vector<vector<int>> permute(vector<int> &nums) {
//    vector<vector<int>> res;
//    vector<int> out;
//    vector<int> visited(nums.size(), 0);
//    DFS(res, out, nums, visited, 0);
//    return res;
//  }
//
//  void DFS(vector<vector<int>> &res, vector<int> out, vector<int> &nums, vector<int> &visited, int level) {
//    if (level == nums.size()) {
//      res.push_back(out);
//    } else {
//      for (int i = 0; i < nums.size(); i++) {
//        if (visited[i] == 0) {
//          visited[i] = 1;
//          out.push_back(nums[i]);
//          DFS(res, out, nums, visited, level + 1);
//          out.pop_back();
//          visited[i] = 0;
//        }
//      }
//    }
//  }
//};

/*
 * 同样使用递归的方法来，但是这里我们不维护一个visited数组来记录我们已经访问过的数组
 * 而是利用交换将需要交换的位置与后面还未定的位置进行交换
 * 空间复杂度O(n),存储是在nums数组中，但是递归时候会需要一个栈空间，最后的栈深度应该为n
 * 对于时间复杂度比较难分析为O(n*n!)，具体看官方的分析https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode-solution-2/
 */
class Solution {
 public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    DFS(res, nums, 0);
    return res;
  }

  void DFS(vector<vector<int>> &res, vector<int> nums, int start) {
    if (start == nums.size()) {
      res.push_back(nums);
    }
    for (int i = start; i < nums.size(); i++) {
      swap(nums[start], nums[i]);
      DFS(res, nums, start + 1);
      swap(nums[start], nums[i]);
    }
  }
};

int main() {

  return 0;
}