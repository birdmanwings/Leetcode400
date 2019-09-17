#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p1 = 0, p2 = 0, num1 = 0, num2 = 0;
        while (p1 < version1.size() || p2 < version2.size()) {
            while (p1 < version1.size() && version1[p1] != '.') {
                num1 = num1 * 10 + version1[p1] - '0';
                p1++;
            }
            while (p2 < version2.size() && version2[p2] != '.') {
                num2 = num2 * 10 + version2[p2] - '0';
                p2++;
            }
            if (num1 > num2) {
                return 1;
            } else if (num1 < num2) {
                return -1;
            }
            num1 = 0;
            num2 = 0;
            p1++;
            p2++;
        }
        return 0;
    }
};

int main() {

    return 0;
}