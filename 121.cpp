//
// Created by bdwms on 2020/7/2.
//
#include "vector"
#include "iostream"

using namespace std;

class Solution {
 public:
  /**
   * @param prices: Given an integer array
   * @return: Maximum profit
   */
  int maxProfit(vector<int> &prices) {
    int res = 0, mn = INT_MAX;
    for (int i = 0; i < prices.size(); ++i) {
      mn = min(mn, prices[i]);
      res = max(res, prices[i] - mn);  // 如果我是在历史最低点买的，那么今天我能卖多少钱呢，其实也是动态规划的思想，自底向上的不断推断
      cout << res << endl;
    }
    return res;
  }
};

int main() {
  vector<int> p = {7, 1, 5, 3, 6, 4};
  Solution s;
  s.maxProfit(p);
}
