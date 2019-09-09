#include <iostream>
#include <vector>

using namespace std;

/*
 *  直接看官方wp，https://leetcode-cn.com/problems/gas-station/solution/jia-you-zhan-by-leetcode/
 */

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int total = 0, sum = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (sum < 0) {
                sum = 0;
                start = i + 1;
            }
        }
        return (total < 0) ? -1 : start;
    }
};

int main() {

    return 0;
}