#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if ((res > INTMAX_MAX / 10) || (res == INTMAX_MAX / 10 && pop > 7)) {
                return 0;
            } else if ((res < INTMAX_MIN / 10) || (res == INTMAX_MIN / 10 && pop < -8)) {
                return 0;
            }
            res = res * 10 + pop;
        }
        return res;
    }
};

int main() {

    return 0;
}