#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int res = 0, n = nums.size(), last = 0, cur = 0;
        for (int i = 0; i < n - 1; i++) {
            cur = max(cur, i + nums[i]);
            if (i == last) {
                last = cur;
                res++;
                if (cur > n - 1)
                    break;
            }
        }
        return res;
    }
};

int main() {

    return 0;
}