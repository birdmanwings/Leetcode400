#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) { //桶排序，抽屉原理
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] < n && nums[i] != nums[nums[i] - 1]) { //遍历数组将值为i的整数交换到下表为i-1的位置
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++) {   //遍历排序后的数组查找到缺失的第一个数字，如果没有则返回n+1
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};

int main() {

    return 0;
}