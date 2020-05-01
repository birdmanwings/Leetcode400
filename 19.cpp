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
 * 时间复杂度O(n),n为链表的长度
 * 空间复杂度O(1)
 */
class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (!head->next) return NULL;
    ListNode *pre = head, *cur = head;
    for (int i = 0; i < n; ++i) cur = cur->next;  // 如果是指到最后一个的时候，直接去掉头节点就行，所以可以直接返回head->next
    if (!cur) return head->next;
    while (cur->next) {
      cur = cur->next;
      pre = pre->next;
    }
    pre->next = pre->next->next;
    return head;
  }
};

int main() {

  return 0;
}