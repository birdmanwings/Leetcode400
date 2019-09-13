#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (needle.size() > haystack.size()) return -1;
        for (int i = 0; i < haystack.size() - needle.size() + 1; i++) {
            int j = 0;
            for (; j < needle.size(); j++) {
                if (needle[j] != haystack[i + j]) {
                    break;
                }
                if (j == needle.size()-1) {
                    return i;
                }
            }
        }
        return -1;
    }
};

int main() {

    return 0;
}