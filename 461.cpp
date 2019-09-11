#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0, exc = x ^ y;
        for (int i = 0; i < 32; ++i) {
            res += (exc >> i) & 1;  //与1表示当最低位为1时得到1
        }
        return res;
    }
};

int main() {

    return 0;
}