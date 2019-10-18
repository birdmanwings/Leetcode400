#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

// 迭代
/*
class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return (dp[amount] > amount) ? -1 : dp[amount];
    }
};
*/
//递归+记忆化数组
class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> memo(amount + 1, INT_MAX);
        memo[0] = 0;
        return coinChangeDFS(coins, amount, memo);
    }

    int coinChangeDFS(vector<int> &coins, int amount, vector<int>& memo) {
        if (amount < 0) {
            return -1;
        }
        if (memo[amount] != INT_MAX) {  //存在已经存储好的记忆时直接返回
            return memo[amount];
        }
        for (int i = 0; i < coins.size(); i++) {
            int tmp = coinChangeDFS(coins, amount - coins[i], memo);
            if (tmp >= 0) {
                memo[amount] = min(memo[amount], tmp + 1);
            }
        }
        return memo[amount] = (memo[amount] == INT_MAX) ? -1 : memo[amount];
    }
};

int main() {

    return 0;
}