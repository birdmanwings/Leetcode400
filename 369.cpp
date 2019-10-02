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
/*
class Solution {    //两次翻转
public:
   ListNode *plusOne(ListNode *head) {
       if (!head) {
           return head;
       }
       ListNode *dummy = new ListNode(-1);
       dummy->next = reverse(head);
       ListNode *cur = dummy->next;
       int m = 1;
       while (cur) {
           if (cur->val + m == 10) {
               m = 1;
               cur->val = 0;
           } else {
               cur->val = cur->val + m;
               m = 0;
           }
           if (cur->next == NULL && m == 1) {
               cur->next = new ListNode(1);
               break;
           }
           cur = cur->next;
       }
       return reverse(dummy->next);
   }

   ListNode *reverse(ListNode *head) { //翻转链表
       if (!head || !head->next) return head;
       ListNode *p = head;
       head = reverse(p->next);   //保存的是新的头部信息
       p->next->next = p; //进行翻转
       p->next = NULL;
       return head;
   }
};
 */
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {       //递归
public:
    ListNode *plusOne(ListNode *head) {
        if (!head) {
            return head;
        }
        int carry = helper(head);
        if (carry == 1) {
            ListNode *res = new ListNode(1);
            res->next = head;
            return res;
        }
        return head;
    }

    int helper(ListNode *head) {
        if (!head) {
            return 1;
        }
        int carry = helper(head->next);
        int sum = head->val + carry;
        head->val = sum % 10;
        return sum / 10;
    }
};

int main() {

    return 0;
}