#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <set>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
class Solution {
public:
    int res = 0;

    int countUnivalSubtrees(TreeNode *root) {
        if (!root) {
            return res;
        }
        if (isUnival(root, root->val)) res++;
        countUnivalSubtrees(root->left);
        countUnivalSubtrees(root->right);
        return res;
    }

    bool isUnival(TreeNode *root, int val) {
        if (!root) {
            return true;
        }
        return root->val == val && isUnival(root->left, val) && isUnival(root->right, val);
    }
};
 */
 class Solution {
 public:
     int countUnivalSubtrees(TreeNode* root) {
         int res;
         isUnival(root, -1, res);
         return res;
     }
     bool isUnival(TreeNode* root, int val, int& res) {
         if (!root) {
             return true;
         }
         if (!isUnival(root->left, root->val, res) | !isUnival(root->right, root->val, res)) {
             return false;
         }
         ++res;
         return root->val == val;
     }
 };

int main() {

    return 0;
}