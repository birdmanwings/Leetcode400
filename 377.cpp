#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<int> dp(target+1,0);//组成和为i的组合数
        dp[0]=1;//使用一个数字组成dp[i]时
        for(int i=1;i<target+1;i++)
            for(auto p:nums)
                if(p<=i)
                {
                    if(dp[i]>INT_MAX-dp[i-p])//防止超int范围
                    {
                        dp[i]=0;//不要返回0 因为i可能不到target 但是有组合和为target
                        break;
                    }
                    dp[i]+=dp[i-p];//dp[i]=sum(dp[i-p]) p=nums[j],p<=i
                }
        return dp[target];
    }
};

int main() {

    return 0;
}