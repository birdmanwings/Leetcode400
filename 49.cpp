#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
 * 时间复杂度O(nklogk),n为外层循环，k为最大字符长度
 * 空间复杂度O(n*k),存在unordered_map中的
 */
//class Solution {
//public:
//    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//        vector<vector<string>> res;
//        unordered_map<string ,vector<string>> m;
//        for (string str:strs) {
//            string t=str;
//            sort(t.begin(), t.end());
//            m[t].push_back(str);
//        }
//        for (auto a:m) {
//            res.push_back(a.second);
//        }
//        return res;
//    }
//};

/*
 * 时间复杂度O(nk)，n个循环乘以最大字符串k
 * 空间复杂度O(nk)
 */
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> m;
    for (string str : strs) {
      vector<int> cnt(26, 0);
      string t = "";
      for (char c : str) ++cnt[c - 'a'];
      for (int d : cnt) t += to_string(d) + "/";
      m[t].push_back(str);
    }
    for (auto a : m) {
      res.push_back(a.second);
    }
    return res;
  }
};


int main() {

  return 0;
}