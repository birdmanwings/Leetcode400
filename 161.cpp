#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.size() < t.size()) {
            swap(s, t);
        }
        int n1=s.size(),n2=t.size(),diff=n1-n2;
        if (diff > 1) {
            return false;
        } else if (diff == 1) {
            for (int i = 0; i < n2; i++) {
                if (s[i] != t[i]) return s.substr(i + 1) == t.substr(i);
            }
            return true;
        } else {
            int c = 0;
            for (int i = 0; i < n1; i++) {
                if (s[i] != t[i]) c++;
            }
            return c == 1;
        }
    }
};

int main() {

    return 0;
}