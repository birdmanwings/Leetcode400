#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) {
            return 0;
        }
        int i = 0, n = str.size(), sign=1, base = 0;    //sign做标志位
        while (i < n && str[i] == ' ') i++; //跳过空格
        if (str[i] == '+' || str[i] == '-') {
            sign = (str[i++] == '+') ? 1 : -1;
        }
        while (i < n && str[i] >= '0' && str[i] <= '9') {
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            base = base * 10 + (str[i++] - '0');
        }
        return base * sign;
    }
};

int main() {

    return 0;
}