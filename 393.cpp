//
// Created by bdwms on 2020/7/5.
//
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

/*
 * 这种方法也是要记连续1的个数，如果是标识字节，先将其向右平移五位，
 * 如果得到110，则说明后面跟了一个字节，否则向右平移四位，如果得到1110，则说明后面跟了两个字节，
 * 否则向右平移三位，如果得到11110，则说明后面跟了三个字节，否则向右平移七位，如果为1的话，说明是10000000这种情况，
 * 不能当标识字节，直接返回false。在非标识字节中，向右平移六位，如果得到的不是10，则说明不是以10开头的，直接返回false，
 * 否则cnt自减1，成功完成遍历返回true，
 */
class Solution {
 public:
  bool validUtf8(vector<int> &data) {
    int cnt = 0;
    for (int d : data) {
      if (cnt == 0) {
        if ((d >> 5) == 0b110) cnt = 1;
        else if ((d >> 4) == 0b1110) cnt = 2;
        else if ((d >> 3) == 0b11110) cnt = 3;
        else if (d >> 7) return false;
      } else {
        if ((d >> 6) != 0b10) return false;
        --cnt;
      }
    }
    return cnt == 0;
  }
};

int main() {
  vector<int> n{255};
  Solution s;
  if (s.validUtf8(n)) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
}
