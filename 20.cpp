#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

/*
 * 栈
 * 时间复杂度O(n)
 * 空间复杂度O(n)
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                p.push(s[i]);
            else {
                if (p.empty()) return false;
                if (s[i] == ')' && p.top() != '(') return false;
                if (s[i] == ']' && p.top() != '[') return false;
                if (s[i] == '}' && p.top() != '{') return false;
                p.pop();
            }
        }
        return p.empty();
    }
};

int main() {

    return 0;
}