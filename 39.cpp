#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
 * 递归的写法,
 * 我们需要先排序来减小搜索的次数，其实就是利用递归来写分支，当减到0的时候成功，<0的时候就不成功，但是这样做肯定会导致重复
 * 那么我们就需要来避免，那就要让分支上的值小于上一层节点的值，才能避免重复
 * 额，这里不太会分析复杂度了
 * 时间复杂度O()
 * 空间复杂度O()
 */
class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> out;
    sort(candidates.begin(), candidates.end());
    combinationSumDFS(candidates, target, res, 0, out);
    return res;
  }

  void combinationSumDFS(vector<int> &candidates, int target, vector<vector<int>> &res, int start, vector<int> out) {
    if (target < 0) {
      return;
    } else if (target == 0) {
      res.push_back(out);
      return;
    }
    for (int i = start; i < candidates.size(); i++) {
      out.push_back(candidates[i]);
      combinationSumDFS(candidates, target - candidates[i], res, i, out);
      out.pop_back();
    }
  }
};

/*
 * 还可以用dp但是，但是是三维的了感觉有点麻烦
 */

int main() {

  return 0;
}