//
// Created by bdwms on 2020/4/29.
//
#include <string>
#include <vector>
using namespace std;

/*
 * 中心拓展算法
 * 时间复杂度O(n^2),因为遍历是2n-1,展开式是n，所以综合是O(n^2)
 * 空间复杂度只需要保存start,maxLen，所以是O(1)
 */
//
//class Solution {
// public:
//  string longestPalindrome(string s) {
//    int len = s.size(), maxLen = 0, start = 0;
//    if (len < 2) {
//      return s;
//    }
//    for (int i = 0; i < len - 1; i++) {
//      // 两种情况，回文有可能是aba,或者abba两种形式
//      searchPalindrome(s, i, i, start, maxLen);
//      searchPalindrome(s, i, i + 1, start, maxLen);
//    }
//    return s.substr(start, maxLen);
//  }
//
//  void searchPalindrome(string s, int left, int right, int &start, int &maxLen) {
//    while (left >= 0 && right < s.size() && s[left] == s[right]) {
//      --left;
//      ++right;
//    }
//    if (maxLen < right - left - 1) {
//      start = left + 1;
//      maxLen = right - left - 1;
//    }
//  }
//};

/*
 * DP
 * dp[i,j]=1 i==j
 * s[i]==s[j] i==j+1
 * s[i] == s[j] && dp[i + 1][j - 1] j > i + 1
 * 时间复杂度O(n^2)
 * 空间复杂度O(n^2)
 */
class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.empty()) return "";
    int left = 0, right = 0, len = 0;
    vector<vector<int>> dp(s.size(), vector<int>(s.size()));
    for (int i = 0; i < s.size(); i++) {
      for (int j = 0; j < s.size(); j++) {
        dp[j][i] = (s[i] == s[j] && i - j < 2) || (s[i] == s[j] && dp[j + 1][i - 1]);
        if (dp[j][i] && len < i - j + 1) {
          len = i - j + 1;
          left = j;
          right = i;
        }
      }
      dp[i][i] = 1;
    }
    return s.substr(left, right - left + 1);
  }
};

/*
 * 马拉车算法Manacher's Algorithm
 * 太麻烦了。。。困了，回头补
 */