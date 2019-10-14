#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
*/
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) {
                return nums[pos];
            } else if (pos > k - 1) {
                right = pos - 1;
            } else {
                left = pos + 1;
            }
        }
    }

    int partition(vector<int> &nums, int left, int right) { //
        int tmp = nums[left], l = 1 + left, r = right;
        while (l <= r) {
            if (nums[l] < tmp && nums[r] > tmp) {   //让左边大，右边小
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= tmp) {
                l++;
            }
            if (nums[r] <= tmp) {
                r--;
            }
            swap(nums[left], nums[r]);  //将挖坑的那个数组放在最后的位置
            return r;
        }
    }
};

int main() {

    return 0;
}