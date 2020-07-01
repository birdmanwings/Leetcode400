//
// Created by bdwms on 2020/6/27.
//
#include "vector"

using namespace std;

/*
 * dfs来做的
 */
class Solution {
 public:
  int findCircleNum(vector<vector<int>> &M) {
    if (M.empty()) {
      return 0;
    }
    int n = M.size(), cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (M[i][j] != 1) {
          continue;
        }
        cnt++;
        dfs(M, i, j);
      }
    }
    return cnt;
  }

  void dfs(vector<vector<int>> &M, int i, int j) {
    M[i][j] = -1;
    for (int k = 0; k < M.size(); k++) {
      if (M[j][k] == 1) {
        dfs(M, j, k);
      }
    }
  }
};


/*
 * 并查集的做法
 * 一共有n个人，所以就是有n个结点，一开始都只指向自己
 * getRoot函数用来不断递归往上找自己指向的父节点，知道有一个循环指向说明找到了根，返回根的序号
 * 判断两个结点的根是否相同，不相同的话说明两个结点不互相联通，res--，然后将起连接起来说明已经查过一次了，避免重复查
 * 时间复杂度：O(n^3)，访问整个矩阵一次，并查集操作需要最坏 O(n) 的时间。
 * 空间复杂度：O(n)
 */
class Solution {
 public:
  int findCircleNum(vector<vector<int>> &M) {
    int n = M.size(), res = n;
    vector<int> root(n);
    for (int i = 0; i < n; ++i) root[i] = i;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (M[i][j] == 1) {
          int p1 = getRoot(root, i);
          int p2 = getRoot(root, j);
          if (p1 != p2) {
            --res;
            root[p2] = p1;
          }
        }
      }
    }
    return res;
  }
  int getRoot(vector<int> &root, int i) {
    while (i != root[i]) {
      root[i] = root[root[i]];
      i = root[i];
    }
    return i;
  }
};
