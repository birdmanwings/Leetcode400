#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size(), cur = 0;
        for (int i = 0; i < n; ++i) {
            if (intervals[i].back() < newInterval.front()) {
                res.push_back(intervals[i]);
                ++cur;
            } else if (intervals[i].front() > newInterval.back()) {
                res.push_back(intervals[i]);
            } else {
                newInterval.front() = min(newInterval.front(), intervals[i].front());
                newInterval.back() = max(newInterval.back(), intervals[i].back());
            }
        }
        res.insert(res.begin() + cur, newInterval);
        return res;
    }
};

/*
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        int n = intervals.size(), cur = 0;
        vector<vector<int>> res;
        while (cur < n && intervals[cur].back() < newInterval.front()) {
            res.push_back(intervals[cur]);
            cur++;
        }
        while (cur < n && intervals[cur].front() <= newInterval.back()) {
            newInterval.front() = min(intervals[cur].front(), newInterval.front());
            newInterval.back() = max(intervals[cur].back(), newInterval.back());
            cur++;
        }
        res.push_back(newInterval);
        while (cur < n) {
            res.push_back(intervals[cur]);
            cur++;
        }
        return res;
    }
};
 */

/*
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.insert(intervals.end(),newInterval);
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
*/

int main() {

    return 0;
}