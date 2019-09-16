#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) {
            return "";
        }
        string res = "1";
        for (int i = 0; i < n-1; i++) {
            string cur = "";
            for (int j = 0; j < res.size(); j++) {
                int num = 1;
                while (j + 1 < res.size() && res[j] == res[j + 1]) {
                    num++;
                    j++;
                }
                cur += to_string(num) + res[j];
            }
            res = cur;
        }
        return res;
    }
};

int main() {

    return 0;
}