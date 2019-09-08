#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size()==0) //利用快慢指针
            return 0;
        int i = 0;
        int j;
        for (j = 0; j < nums.size(); ++j) {
            if (nums[i] != nums[j]){
                nums[++i] = nums[j];
            }
        }
        return i+1;
    }
};

int main() {
    vector<int> nums = {1, 2, 2, 3};
    int val = 2;
    Solution S;
    //cout << nums.size() << endl;
    cout << S.removeDuplicates(nums) << endl;
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
    return 0;
}