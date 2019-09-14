#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int wordIndex = 0, n = s.size(); //wordIndex用来记录是第几个单词
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (wordIndex != 0) {
                    s[wordIndex++] = ' ';
                }
                int j = i;
                while (j < n && s[j] != ' ') s[wordIndex++] = s[j++];
                reverse(s.begin() + wordIndex - (j - i), s.begin() + wordIndex);
                i = j;
            }
        }
        s.resize(wordIndex);
    }
};

int main() {

    return 0;
}