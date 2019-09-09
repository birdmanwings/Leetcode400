#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

/*
 * 先降序排序后，当如果citations[i]>i，那么说明第 0 到 i 篇论文都有至少 i+1 次引用
 */
class Solution {
public:
    int hIndex(vector<int> &citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] <= i) {
                return i;
            }
        }
        return citations.size();
    }
};

int main() {

    return 0;
}