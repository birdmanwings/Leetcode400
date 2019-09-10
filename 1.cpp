#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> m;
        int temp;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) { //做一个哈希映射，值对应下标，因为要求返回的是下标
            m[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            temp = target - nums[i];
            if (m.count(temp) && m[temp] != i) {
                res.push_back(i);
                res.push_back(m[temp]);
                break;
            }
        }
        return res;
    }
};
*/

class Solution {    //一次循环版本
public:
    vector<int> twoSum(vector<int>& nums, int target) {
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