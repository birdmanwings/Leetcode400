#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/*
 * 时间复杂度是O(max(l1,l2))
 * 空间复杂度是O(max(l1,l2)),最大为max(l1,l2)+1
 */
class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    auto *res = new ListNode(-1);
    ListNode *cur = res;
    int carry = 0, n1, n2, sum;
    while (l1 || l2) {
      n1 = l1 ? l1->val : 0;
      n2 = l2 ? l2->val : 0;
      sum = n1 + n2 + carry;
      carry = sum > 9 ? 1 : 0;
      cur->next = new ListNode(sum % 10);
      cur = cur->next;
      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
    }
    if (carry) cur->next = new ListNode(1);  // pay attention to carry
    return res->next;
  }
};

int main() {

  return 0;
}