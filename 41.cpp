#include <iostream>
#include <vector>

using namespace std;

/*
 * 其实是利用自己数组本身来做hash，key为下标，value为相应下标的值，即nums[key]=key+1
 * 时间复杂度O(n),因为只有当nums[i] != nums[nums[i] - 1]时才会触发swap，最坏情况是每一次都触发，所以触发n次是O(n)
 * 空间复杂度O(1)，没有另外开辟空间
 */
class Solution {
public:
    int firstMissingPositive(vector<int> &nums) { //桶排序，抽屉原理
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] < n && nums[i] != nums[nums[i] - 1]) { //遍历数组将值为i的整数交换到下表为i-1的位置
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++) {   //遍历排序后的数组查找到缺失的第一个数字（即下表为i的地方存在值应该是i+1），如果没有则返回n+1
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};

int main() {

    return 0;
}