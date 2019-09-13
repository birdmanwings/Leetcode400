#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) { return a.front() < b.front(); });
        priority_queue<int, vector<int>, greater<int>> q; //声明一个小顶堆
        for (auto a:intervals) {
            if (!q.empty() && q.top() <= a.front()) {   //如果堆非空并且堆顶元素即结束时间小于下个会议的开始时间，那么当前元素出堆
                q.pop();
            }
            q.push(a.back());
        }
        return q.size();
    }
};

int main() {
    return 0;
}