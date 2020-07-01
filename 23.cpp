//
// Created by bdwms on 2020/6/30.
//
#include "vector"
#include "queue"
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
 * 优先队列，小顶堆来做
 */
//struct cmp {
//  bool operator()(ListNode *a, ListNode *b) {
//    return a->val > b->val;
//  }
//};
//
//class Solution {
// public:
//  ListNode *mergeKLists(vector<ListNode *> &lists) {
//    priority_queue<ListNode *, vector<ListNode *>, cmp> q;
//    for (auto l:lists) {
//      if (l) q.push(l);
//    }
//    ListNode *head = NULL, *pre = NULL, *temp = NULL;
//    while (!q.empty()) {
//      temp = q.top();
//      q.pop();
//      if (!pre) {
//        head = temp;
//      } else {
//        pre->next = temp;
//      }
//      pre = temp;
//      if (temp->next) {
//        q.push(temp->next);
//      }
//    }
//    return head;
//  }
//};

/*
 * 分治法来转换为合并两个链表
 */
class Solution {
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0) return NULL;
    int n = lists.size();
    while (n > 1) {
      int k = (n + 1) / 2;
      for (int i = 0; i < n / 2; ++i) {
        lists[i] = mergeTwoLists(lists[i], lists[i + k]);
      }
      n = k;
    }
    return lists[0];
  }

  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
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
    if (l1) cur->next = l1;
    if (l2) cur->next = l2;
    return temp->next;
  }
};