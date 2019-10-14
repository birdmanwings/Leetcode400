#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m;
        for (auto a:s) {
            m[a]++;
        }
        for (auto a:t) {
            m[a]--;
            if (m[a]<0) {
                return a;
            }
        }
        return 0;
    }
};
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for (char c : s) res ^= c;
        for (char c : t) res ^= c;
        return res;
    }
};

int main() {

    return 0;
}