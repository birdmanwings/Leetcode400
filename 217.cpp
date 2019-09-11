#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end()) //end()是返回结束位置的迭代器，这里的意思就是能够找到值为nums[i]
                return true;
            m[nums[i]]++;   //在这里unordered_map里面的第二个的int初始化值为0，这里是STL内置的，所以++会让值变为非0
        }
        return false;
    }

private:
    unordered_map<int, int> m;
};

/**先排序在看两边的值是否相同
 * class Solution {
 * public:
 * bool containsDuplicate(vector<int> &nums) {
 *      sort(nums.begin(), nums.end());
 *      for (int i = 1; i < nums.size(); ++i) {
 *          if (nums[i] == nums[i - 1]) return true;
 *      }
 *      return false;
 *  }
 * };
 */

int main() {

    return 0;
}