#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int i = 0;
        int j = 0;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                continue;
            }
            nums[j++] = nums[i];
        }
        return j;
    }
};

int main() {
    vector<int> nums = {1, 2, 2, 3, 4};
    int val = 2;
    Solution S;
    cout << S.removeElement(nums, val) << endl;
    return 0;
}