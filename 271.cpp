#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs) {
        string res = "";
        for (auto a:strs) {
            res.append(to_string(a.size())).append("/").append(a);
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        while (i < s.size()) {
            auto find = s.find("/", i);
            int len = atoi(s.substr(i, find).c_str());  //atoi是C的需要是char指针但是这里是C++的string所以要用c.str返回const 指针
            res.push_back(s.substr(find + 1, len));
            i = find + len + 1;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

int main() {

    return 0;
}