//
// Created by bdwms on 2020/7/4.
//
#include "vector"

using namespace std;

/*
 * dp,先排序，默认sort就可以直接排序了，然后遍历前面的信封比较长宽都大的话，更新dp
 */
class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    int res=0;
    int n = envelopes.size();
    vector<int> dp(n,1);
    sort(envelopes.begin(),envelopes.end());
    for(int i =0;i<n;i++){
      for(int j=0;j<i;j++){
        if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
          dp[i]=max(dp[i],dp[j]+1);
        }
      }
      res = max(res,dp[i]);
    }
    return res;
  }
};
