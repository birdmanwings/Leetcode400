#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (x + y) >= z && z % gcd(x, y) == 0;
    }

    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
};

int main() {

    return 0;
}