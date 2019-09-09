#include <iostream>
#include <vector>


using namespace std;
/*
 * 一.二分的时间复杂度为O(log^N)
 * 二.h成立条件倒数第h个数大于等于h,即citations[len - mid] >= mid
 * 三.h成立时，小于h的都成立，要向右边试探直到条件二不成立，得到最大的h
 */
class Solution {
public:
    int hIndex(vector<int> &citations) {
        int right = citations.size(), left = 0, mid, len = citations.size();
        while (left < right) {
            mid = (right + left + 1) / 2;
            if (citations[len - mid] >= mid) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main() {

    return 0;
}