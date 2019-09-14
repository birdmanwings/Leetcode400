#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void reverseString(vector<char> &s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
};

int main() {

    return 0;
}