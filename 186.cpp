#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseWords(vector<char>& s) {
        int n = s.size();
        for (int i = 0, j = 0, p, tmp; i < n; ++i) { //j为存储单词开始的地方的下标
            if (s[i] == ' ') {
                tmp = (i - j) / 2; //tmp为交换次数，后面while循环用于交换
                p = i;
                while (tmp--) swap(s[j++], s[--p]);
                j = i + 1; //将j改为下个单词开始的地方
            }
            if (i == n - 1) { //分类讨论
                tmp = (i - j + 1) / 2; //这时候因为没遇到空格，i比上一种情况少1，于是这边+1
                p = i;
                while (tmp--) swap(s[j++], s[p--]); //这边要用p--
            }
        }
        for (int i = 0; i < n / 2; ++i) swap(s[i], s[n - i - 1]); //最后全部翻转即可，也可以先翻转后交换
        return;
    }
};

int main() {

    return 0;
}