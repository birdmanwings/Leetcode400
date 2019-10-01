#include <iostream>
#include <vector>
#include <climits>
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
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val =node->next->val;
        ListNode *tmp=node->next;
        node->next=tmp->next;
        delete tmp;
    }
};

int main() {

    return 0;
}