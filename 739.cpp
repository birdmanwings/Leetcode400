//
// Created by bdwms on 2020/8/2.
//
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int> &T) {
    stack<int> s;
    int nums = T.size();
    vector<int> res(nums, 0);
    for (int i = 0; i < nums; i++) {
      if (s.empty() || s.top() >= T[i]) {
        s.push(T[i]);
      } else {
        int n = 0;
        while (s.top() < T[i]) {
          s.pop();
          n++;
          if (s.empty()) {
            break;
          }
        }
        //cout << "n: " << n << endl;
        for (int j = 1; j <= n; j++) {
          res[i - j] = j;
        }
        for (int k = 0; k <= s.size(); k++) {
          res[i - n - 1 + k]++;
        }
        s.push(T[i]);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> v = {73, 74, 75, 71, 69, 72, 76, 73};
  vector<int> result = s.dailyTemperatures(v);
  for (auto x:result) {
    cout << x << endl;
  }
  return 0;
}