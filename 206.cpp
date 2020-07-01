#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
class Solution {
public:
   ListNode *reverseList(ListNode *head) {
       if (!head) {
           return head;
       }
       ListNode *d = new ListNode(-1);
       d->next = head;
       ListNode *cur = head;
       while (cur->next) {
           ListNode *tmp = cur->next;
           cur->next = tmp->next;
           tmp->next = d->next;
           d->next = tmp;
       }
       return d->next;
   }
};
*/

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *reverseList(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *p = head;
    head = reverseList(p->next);   //保存的是新的头部信息
    p->next->next = p; //进行翻转
    p->next = NULL;
    return head;
  }
};
int main() {

  return 0;
}