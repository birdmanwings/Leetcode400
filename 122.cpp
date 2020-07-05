//
// Created by bdwms on 2020/7/3.
//
#include "vector"

using namespace std;

/*
 * 把所有上升线段都算进去就行了
 */
class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int res = 0;
    for (int i = 0; i < prices.size() - 1; i++) {
      if (prices[i] < prices[i + 1]) {
        res += prices[i + 1] - prices[i];
      }
    }
    return res;
  }
};

