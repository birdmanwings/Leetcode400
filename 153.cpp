#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        if (nums[left] > nums[right]) {
            while (left != right - 1) {
                int mid = left + (right - left) / 2;
                if (nums[left] < nums[mid]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            return min(nums[left], nums[right]);
        }
        return nums[left];
    }
};

int main() {

    return 0;
}