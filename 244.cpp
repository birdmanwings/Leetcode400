#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>

using namespace std;

/*
 * 因为要多次查询，这时候建立hash表就比较好，当调用shortest函数时就直接查Hash表得到位置数组，然后
 * 根据https://leetcode-cn.com/problems/shortest-word-distance-ii/solution/zui-duan-dan-ci-ju-chi-ii-by-leetcode/
 * 来求得最短距离
 */
class WordDistance {
public:
    WordDistance(vector<string> &words) {
        for (int i = 0; i < words.size(); i++) {
            m[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int i = 0, j = 0, res = INT_MAX;
        while (i < m[word1].size() && j < m[word2].size()) {
            res = min(res, abs(m[word1][i] - m[word2][j]));
            m[word1][i] < m[word2][j] ? ++i : ++j;
        }
        return res;
    }

private:
    unordered_map<string, vector<int>> m;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */

int main() {

    return 0;
}