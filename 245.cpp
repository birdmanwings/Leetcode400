#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string> &words, string word1, string word2) {
        int p1 = -1, p2 = -1, res = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            int temp = p1;
            if (words[i] == word1) p1 = i;
            if (words[i] == word2) p2 = i;
            if (p1 != -1 && p2 != -1) {
                if (word1 == word2 && temp != -1 && temp != p1) {
                    res = min(res, abs(temp - p1));
                } else if (p1 != p2) {
                    res = min(res, abs(p1 - p2));
                }
            }
        }
        return res;
    }
};

int main() {

    return 0;
}