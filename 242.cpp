#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> m;
        for (auto c:s) {
            m[c]++;
        }
        for (auto c:t) {
            m[c]--;
        }
        for (auto& c:m) {
            if (c.second != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s = "a", t = "b";
    Solution S;
    S.isAnagram(s, t);
    return 0;
}