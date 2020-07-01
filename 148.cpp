//
// Created by bdwms on 2020/6/29.
//

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
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode *pre = head, *slow = head, *quick = head;
    while (quick && quick->next) {
      pre = slow;
      slow = slow->next;
      quick = quick->next->next;
    }
    pre->next = NULL;
    return merge(sortList(head), sortList(slow));
  }

  ListNode *merge(ListNode *l1, ListNode *l2) {
    ListNode *temp = new ListNode(-1);
    ListNode *cur = temp;
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
    return temp->next;
  }
};