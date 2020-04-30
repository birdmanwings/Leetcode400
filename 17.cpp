//
// Created by bdwms on 2020/4/30.
//
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 递归
 * 时间复杂度O(3^N*4^M),N为三个字母的键个数，M同理
 * 空间复杂度O(3^N*4^M)
 */
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return {};
    }
    vector<string> res;
    string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    letterCombinationsDFS(digits, dict, 0, "", res);
    return res;
  }

  void letterCombinationsDFS(string digits, string dict[], int level, string out, vector<string> &res) {
    if (level == digits.size()) {
      res.push_back(out);
      return;
    }
    string str = dict[digits[level] - '0'];
    for (int i = 0; i < str.size(); i++) {
      letterCombinationsDFS(digits, dict, level + 1, out + string(1, str[i]), res);
    }
  }
};