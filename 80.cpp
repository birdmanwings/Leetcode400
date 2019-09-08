#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 2)
            return nums.size();
        int count = 1; //count用来记录重复次数
        int i = 0;
        int j;
        for (j = 1; j < nums.size(); j++) {
            if (count == 1) {
                if (nums[i] == nums[j]) {
                    count = 0;
                    nums[++i]=nums[j];  //这里也要往后递进下，虽然重复了
                } else {
                    nums[++i] = nums[j];
                }
            } else {
                if (nums[i] != nums[j]) {
                    count = 1;    //因为数组是有序的当出现不同时，count可以直接变回1
                    nums[++i] = nums[j];
                }
            }
        }
        return i + 1;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1, 2, 3, 3};
    int val = 2;
    Solution S;
    cout << S.removeDuplicates(nums) << endl;
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
    return 0;
}