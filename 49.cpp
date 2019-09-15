#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string ,vector<string>> m;
        for (string str:strs) {
            string t=str;
            sort(t.begin(), t.end());
            m[t].push_back(str);
        }
        for (auto a:m) {
            res.push_back(a.second);
        }
        return res;
    }
};

int main() {

    return 0;
}