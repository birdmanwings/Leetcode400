//
// Created by bdwms on 2020/6/21.
//
#include "iostream"
#include "vector"
using namespace std;

/*
 * 快排，挖坑法
 */
void quick_sort(vector<int> &s, int l, int r) {
  if (l < r) {
    int temp = s[l], i = l, j = r;
    while (i < j) {
      while (i < j && s[j] >= temp) {
        j--;
      }
      s[i++] = s[j];
      while (i < j && s[i] < temp) {
        i++;
      }
      s[j--] = s[i];
    }
    s[i] = temp;
    quick_sort(s, l, i - 1);
    quick_sort(s, i + 1, r);
  }
}

int main() {
  vector<int> array={34, 65, 12, 43, 67, 5, 78, 10, 3, 70};
  quick_sort(array, 0, 9);
  for (auto i : array) {
    cout << i << endl;
  }
}