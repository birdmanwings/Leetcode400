#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += pow(26, s.size() - i - 1) * (s[i] - 'A' + 1);
        }
        return res;
    }
};

int main() {

    return 0;
}