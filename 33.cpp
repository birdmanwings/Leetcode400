#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * 观察所有的旋转数组
 * 0　　1　　2　　4　　5　　6　　7
 * 7　　0　　1　　2　　4　　5　　6
 * 6　　7　　0　　1　　2　　4　　5
 * 5　　6　　7　　0　　1　　2　　4
 * 4　　5　　6　　7　　0　　1　　2
 * 2　　4　　5　　6　　7　　0　　1
 * 1　　2　　4　　5　　6　　7　　0
 * 因为是要求O(log^n)，肯定是二分，那么二分的关键就在于，我们找到mid点的时候，需要判断target的位置是属于左边还是右边
 * 然后我们观察数组能够发现，当中间值处于右边的升序队列时候，我们可以发现当mid值小于最右边的值的时候，那么mid右边的数是有序的
 * 当大于的时候，则左边是有序的，那么我们就可以先得出哪一部分是有序的，然后才能判断target是否在这个有序序列中，然后就能修正left或者right
 * 从而不断折叠二分。
 * 总结下，我们做类似这种题目的时候可以先把所有例子举出来，来便于我们观察规律，然后要剖析到关键点。
 * 时间复杂度O(logn)
 * 空间复杂度O(1)
 */
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1; // 注意下=边界情况
                else right = mid - 1;
            } else {
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};



int main() {

    return 0;
}