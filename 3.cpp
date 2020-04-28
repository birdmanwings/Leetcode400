//
// Created by bdwms on 2020/4/28.
//
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
 * 时间复杂度O(2n)=O(n),最坏的情况是left,right都扫描全一遍
 * 空间复杂度为O(min(m,n)),也就是set的大小，m为字符集大小，n为最长字符长大小，
 * 维护一个滑动窗口，right一路扫过去，将不重复的放进set里面,然后重复时left++，并从set中删除原来的那一位，继续从right往右边扫，
 * 因为已经扫过了，不要从left那里重新扫，节约了时间
 */
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int res = 0, left = 0, right = 0, len = s.size();
    unordered_set<char> st;
    while (res < len - left) {
      if (!st.count(s[right])) {
        st.insert(s[right++]);
        res = max(res, (int) st.size());
      } else {
        st.erase(s[left++]);
      }
    }
    return res;
  }
};

int main() {

}