#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string> &strings) {
        vector<vector<string>> res;
        unordered_map<string, multiset<string>> m; //做hash映射
        for (auto a: strings) {
            string t = "";
            for (auto c :a) {
                t += to_string((c - a[0] + 26) % 26) + ","; //利用相对距离一样
            }
            m[t].insert(a);
        }
        for (auto i = m.begin(); i != m.end(); ++i) {
            res.push_back(vector<string>(i->second.begin(), i->second.end()));
        }
        return res;
    }
};

int main() {

    return 0;
}