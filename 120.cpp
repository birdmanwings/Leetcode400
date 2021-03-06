#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * 逆向思维来做dp,我从最后一行往上做dp
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(triangle.back());
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};

int main() {

    return 0;
}