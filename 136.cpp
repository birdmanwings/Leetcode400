#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int res = 0;
        for (auto a:nums) {
            res ^= a;
        }
        return res;
    }
};

int main() {

    return 0;
}