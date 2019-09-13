#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) { return a.front() < b.front(); });
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].front() < intervals[i - 1].back()) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<int>> a = {{7, 10},
                             {2, 4}};
    Solution S;
    S.canAttendMeetings(a);
    return 0;
}