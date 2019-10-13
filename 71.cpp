#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        int i = 0;
        while (i < path.size()) {
            while (path[i] == '/' && i < path.size()) ++i;  //  去除多余的/
            if (i == path.size()) break;
            int start = i;
            while (path[i] != '/' && i < path.size()) ++i;  //记录名字
            int end = i - 1;
            string s = path.substr(start, end - start + 1); //截取名字
            if (s == "..") {    // 如果是上级目录，则删除一个，否则压入数组中名字
                if (!v.empty()) v.pop_back();
            } else if (s != ".") {
                v.push_back(s);
            }
        }
        if (v.empty()) return "/";
        string res;
        for (int i = 0; i < v.size(); ++i) {
            res += '/' + v[i];
        }
        return res;
    }
};

int main() {

    return 0;
}