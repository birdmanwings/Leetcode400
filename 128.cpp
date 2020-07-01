//
// Created by bdwms on 2020/6/27.
//
#include "vector"
#include "unordered_set"

using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int> &nums) {
    int res = 0;
    unordered_set<int> s(nums.begin(), nums.end());
    for (auto n:nums) {
      if (!s.count(n)) continue;
      s.erase(n);
      int pre = n - 1;
      int next = n + 1;
      while (s.count(pre)) s.erase(pre--);
      while (s.count(next)) s.erase(next++);
      res = max(res, next - pre - 1);
    }
    return res;
  }
};