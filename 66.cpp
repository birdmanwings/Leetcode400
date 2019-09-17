#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

/*
 * 从后向前，找到第一个不为9的数，该位+1，该位后的数均变为0；
 * 未找到的话，说明该数全为9，则返回 1 加 digits.size()个0
 */
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();
        for (int i = len - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i]++;
                return digits;
            } else {
                digits[i] = 0;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    return 0;
}

/*
 * vector<int> res;
        long int num = 0;
        for (int i = 0; i < digits.size(); i++) {
            num += pow(10, i) * digits[digits.size()-i-1];
        }
        num++;
        while (num > 0) {
            res.push_back(num % 10);
            num /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
 */