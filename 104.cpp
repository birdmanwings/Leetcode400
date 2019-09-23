#include <iostream>
#include <vector>
#include <queue>

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
    int maxDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 1;
        }
        if (!root->left) {
            return 1 + maxDepth(root->right);
        } else if (!root->right) {
            return 1 + maxDepth(root->left);
        } else {
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        }
    }
};

int main() {

    return 0;
}