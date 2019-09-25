#include <iostream>
#include <vector>

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
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MAX, LONG_MIN);
    }

    bool isValidBST(TreeNode *node, long max, long min){
        if (!node) {
            return true;
        }
        if (node->val >= max || node->val <= min) {
            return false;
        }
        return isValidBST(node->left, node->val, min) && isValidBST(node->right, max, node->val);
    }
};

int main() {

    return 0;
}