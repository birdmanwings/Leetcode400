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
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre;
        pre = dummy;
        while (pre && pre->next) {
            ListNode *cur = pre->next;
            while (cur->next && cur->val == cur->next->val) {
                cur = cur->next;
            }
            if (cur != pre->next) {
                pre->next = cur->next;
            } else {
                pre = pre->next;
            }
        }
        return dummy->next;
    }
};

int main() {

    return 0;
}