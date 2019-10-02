#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * 当短的链表遍历到末尾时，长的还差两者长度距离到末尾，这时短的指针从长的开始遍历然后弥补了两者之间的长度之差，此时长指针走得路径相当于无效路径
 * 只是为了弥补两者之间的长度差。
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return NULL;
        }
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};

int main() {

    return 0;
}