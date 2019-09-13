#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {  //纵向遍历，还有多解回头看
        if (strs.empty()) {
            return "";
        }
        string res = "";
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 0; j < strs.size(); j++) {
                if (strs[0][i] != strs[j][i] || i >= strs[j].size()) {
                    return res;
                }
            }
            res.push_back(strs[0][i]);
        }
        return res;
    }
};

int main() {

    return 0;
}