#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        if (nums.back() < target) {
            return nums.size();
        }
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right=mid;
            } else if (nums[mid] < target) {
                left=mid+1;
            } else {
                return mid;
            }
        }
        return right;
    }
};

int main() {

    return 0;
}