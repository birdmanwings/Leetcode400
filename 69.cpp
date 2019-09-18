#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }
        int left = 0, right = x;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x / mid >= mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return right - 1;
    }
};

/* 牛顿法
 *
 * long res = x;
        while (res * res > x) {
            res = (res + x / res) / 2;
        }
        return res;

 */

int main() {

    return 0;
}