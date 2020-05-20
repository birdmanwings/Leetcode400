#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
 * 四个数循环，一个倒三角的旋转
 * 时间复杂度O(n^2),因为是双重循环
 * 空间复杂度O(1)
 */
//class Solution {
//public:
//    void rotate(vector<vector<int>> &matrix) {
//        int n = matrix.size();
//        for (int i = 0; i < n / 2; i++) {
//            for (int j = i; j < n - 1 - i; j++) {
//                int tmp = matrix[i][j];
//                matrix[i][j] = matrix[n - 1 - j][i];
//                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
//                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
//                matrix[j][n - 1 - i] = tmp;
//            }
//        }
//    }
//};

/*
 * 转置矩阵，然后反转每行的数字
 * 时间复杂度O(n^2)
 * 空间复杂度O(1)
 */
class Solution {
 public:
  void rotate(vector<vector<int> > &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }
};

int main() {

    return 0;
}