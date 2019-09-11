#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/**
 * 动态规划
 * 一维数组dp，其中dp[i]表示达到i位置时剩余的步数
 * 状态转移方程：dp[i] = max(dp[i - 1], nums[i - 1]) - 1 ，减1是因为到下一位需要一个跳力
 * 结束条件为：某一个时刻dp数组的值为负了，说明无法抵达当前位置，则直接返回false，最后我们判断dp数组最后一位是否为非负数即可知道是否能抵达该位置
 * 边界应该就是第一个的跳力的n，F(n),F(n-1)...F(1)
 * 最优子结构
 */
class Solution {
public:
    bool canJump(vector<int> &nums) {
        vector<int> dp(nums.size(), 0);
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
            if (dp[i] < 0) return false;
        }
        return dp.back() >= 0;
    }
};

/** 贪婪算法这里只用维护一个常量级空间，更好
 * class Solution {
 * public:
 *     bool canJump(vector<int>& nums) {
 *     int k = 0;
 *  	       for (int i = 0; i < nums.size(); i++){
 *		        if (i > k) return false;
 * 		        k = max(k, i + nums[i]);
 *	        }
 *	    return true;
 *      }
 * };
 * @return
 */

int main() {

    return 0;
}