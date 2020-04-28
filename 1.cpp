#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 最暴力的解法是遍历数组，然后再遍历剩下的数
 * 因为是两层循环，所以时间复杂度是O(n^2),空间复杂度为O(1)
 */

/*
 * 2.两个hash表
 * 先遍历一遍存储到hash表中，再遍历一遍进行寻找，时间复杂度为O(2n)=O(n)
 * 所需的空间取决于数组的大小，所以为O(n)
 */
//class Solution {
//public:
//    vector<int> twoSum(vector<int> &nums, int target) {
//        unordered_map<int, int> m;
//        int temp;
//        vector<int> res;
//        for (int i = 0; i < nums.size(); i++) { //做一个哈希映射，值对应下标，因为要求返回的是下标
//            m[nums[i]] = i;
//        }
//        for (int i = 0; i < nums.size(); i++) {
//            temp = target - nums[i];
//            if (m.count(temp) && m[temp] != i) {
//                res.push_back(i);
//                res.push_back(m[temp]);
//                break;
//            }
//        }
//        return res;
//    }
//};


/*
 * 遍历一遍，所以时间复杂度为O(n)
 * 空间复杂度为O(n)
 */
class Solution {    //一次循环版本
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
      if (m.count(target - nums[i])) {
        return {i, m[target - nums[i]]};
      }
      m[nums[i]] = i;
    }
    return {};
  }
};

int main() {

  return 0;
}