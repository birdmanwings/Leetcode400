//
// Created by bdwms on 2020/6/29.
//
#include "vector"
#include "iostream"

using namespace std;

/*
 * 左右扫描
 */
class Solution {
 public:
  int trap(vector<int> &height) {
    int left = 0, right = height.size() - 1, area = 0, sum = 0, h1, h2 = 0, res;
    for (auto h:height) {  // 计算格子的树木
      sum += h;
    }
    while (left <= right) {  // 计算填充后的面积。利用左右双指针来扫描
      h1 = min(height[left], height[right]);  // h1是移动后左右偏小的高度
      area += (right - left + 1) * (h1 - h2);
      h2 = h1;                                // h2是移动之前的高度，因为瞎下面层的已经计算过了，所以要h1-h2
      if (height[left] <= height[right]) {    // 如果是左边高度低的话，移动左指针，直到找到比原来高的，
        left++;
        while (left <= right && height[left] <= h2) {  // 注意这里要先确保left <= right，否则两个条件互换的话会造成height[left]可能指向未定义的地方了
          left++;
        }
      } else {  // 同上类似
        right--;
        while (left <= right && height[right] <= h2) {
          right--;
        }
      }
    }
    res = area - sum;  // 最后将填充完整的面积减去原来的面积，就是填充的雨滴面积了
    return res;
  }
};

/*
 * 栈的方法，也比较巧妙
 */
//class Solution {
// public:
//  int trap(vector<int>& height) {
//    stack<int> st;
//    int i = 0, res = 0, n = height.size();
//    while (i < n) {
//      if (st.empty() || height[i] <= height[st.top()]) {
//        st.push(i++);
//      } else {
//        int t = st.top(); st.pop();
//        if (st.empty()) continue;
//        res += (min(height[i], height[st.top()]) - height[t]) * (i - st.top() - 1);
//      }
//    }
//    return res;
//  }
//};


int main() {
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  vector<int> h2 = {2, 0, 2};
  vector<int> h3 = {0};
  Solution s;
  int r;
  r = s.trap(h3);
  cout << r << endl;
}