//
// Created by bdwms on 2020/5/1.
//
#include <vector>
#include <string>

using namespace std;

/*
 * 利用递归
 * 时间复杂度O(4^n/n^(1/2)),这里不会证:)
 * 空间复杂度O(2n)=O(n)，是栈的深度
 */
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    generateParenthesisDFS(n, n, "", res);
    return res;
  }

  void generateParenthesisDFS(int left, int right, string out, vector<string> &res) {
    if (left > right) {
      return;
    }
    if (left == 0 && right == 0) {
      res.push_back(out);
    } else {
      if (left > 0) {
        generateParenthesisDFS(left - 1, right, out + '(', res);
      }
      if (right > 0) {
        generateParenthesisDFS(left, right - 1, out + ')', res);
      }
    }
  }
};

/*
 * 第二种解法是这种方法的思想是找左括号，每找到一个左括号，就在其后面加一个完整的括号，最后再在开头加一个()，
 * 就形成了所有的情况，需要注意的是，有时候会出现重复的情况，所以我们用set数据结构，好处是如果遇到重复项，不会加入到结果中，
 * 最后我们再把set转为vector即可，
 */
//class Solution {
// public:
//  vector<string> generateParenthesis(int n) {
//    set<string> t;
//    if (n == 0) t.insert("");
//    else {
//      vector<string> pre = generateParenthesis(n - 1);
//      for (auto a : pre) {
//        for (int i = 0; i < a.size(); ++i) {
//          if (a[i] == '(') {
//            a.insert(a.begin() + i + 1, '(');
//            a.insert(a.begin() + i + 2, ')');
//            t.insert(a);
//            a.erase(a.begin() + i + 1, a.begin() + i + 3);
//          }
//        }
//        t.insert("()" + a);
//      }
//    }
//    return vector<string>(t.begin(), t.end());
//  }
//};