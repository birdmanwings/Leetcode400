#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
/**
 * vector中begin(),end()返回的都是迭代器
 * back(),front()返回的是元素
 * 先排序，再比较边界元素大小
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) { return a.front() < b.front(); });
        vector<vector<int>> res{intervals[0]};
        for (int i = 1; i < intervals.size(); i++) {
            if (res.back().back() < intervals[i].front()){
                res.push_back(intervals[i]);
            }else {
                res.back().back() = max (res.back().back(),intervals[i].back());
            }
        }
        return res;
    }
};

int main() {

    return 0;
}