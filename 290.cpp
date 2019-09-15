#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        istringstream f(str);
        int i = 0;
        for (string word; f >> word; ++i) {
            if (m1.find(pattern[i]) != m1.end() || m2.find(word) != m2.end()) { //Hash表中找到一个映射存在
                if (m1[pattern[i]] != m2[word]) return false;   //当两个Hash表中不对应数量则返回false
            } else {
                m1[pattern[i]] = m2[word] = i + 1;  //用i来区分特别标志，+1是因为防止i=0的情况
            }
        }
        return i == pattern.size();
    }
};

int main() {
    return 0;
}