#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != ' ')
                res++;
            else if (res != 0)
                break;
        }
        return res;
    }
};

int main() {

    return 0;
}