#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        if (nums.size() == 1) {
            return 0;
        }
        nums.insert(nums.begin(), INT_MIN);
        nums.push_back(INT_MIN);
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                return i - 1;
            }
        }
        return -1;
    }
};
 */
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return right;
    }
};

int main() {

    return 0;
}