#include <iostream>
#include <vector>

using namespace std;

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    void rotate(vector<int> &nums, int k) { //翻转数组，前n-k个数组先翻转下，再翻转后k个，最后翻转整个数组
        if (nums.empty() || (k %= nums.size()) == 0) return;
        int n = nums.size();
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};
    int k = 3;
    Solution S;
    S.rotate(nums, k);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
    return 0;
}