#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

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
 * 新建一个链表用来存储结果
 * 时间复杂度O(max(l1,l2))
 * 空间复杂度O(len1+len2)
 */
class Solution {
 public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *res = new ListNode(-1), *cur = res;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        cur->next = l1;
        l1 = l1->next;
      } else {
        cur->next = l2;
        l2 = l2->next;
      }
      cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    return res->next;
  }
};

/*
 * 利用递归的方法
 * 时间复杂度O(max(l1,l2))
 * 空间复杂度O(1)
 */
//class Solution {
// public:
//  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
//    if (!l1) return l2;
//    if (!l2) return l1;
//    if (l1->val < l2->val) {
//      l1->next = mergeTwoLists(l1->next, l2);
//      return l1;
//    } else {
//      l2->next = mergeTwoLists(l1, l2->next);
//      return l2;
//    }
//  }
//};

int main() {

  return 0;
}