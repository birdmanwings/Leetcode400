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
   ListNode *swapPairs(ListNode *head) {
       ListNode *dummy = new ListNode(-1), *pre = dummy;
       dummy->next = head;
       while (pre->next && pre->next->next) {
           ListNode *t = pre->next->next;
           pre->next->next = t->next;
           t->next = pre->next;
           pre->next = t;
           pre = t->next;
       }
       return dummy->next; //dummy用来记录头节点的位置
   }
};
*/
class Solution {    //递归
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *t = head->next;
        head->next = swapPairs(head->next->next);
        t->next = head;
        return t;
    }
};

int main() {

    return 0;
}