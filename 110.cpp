#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
    bool isBalanced(TreeNode *root) {
        if (checkDepth(root) == -1) {
            return false;
        }else return true;
    }

    int checkDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left = checkDepth(root->left);
        if (left == -1) {
            return -1;
        }
        int right = checkDepth(root->right);
        if (right == -1) {
            return -1;
        }
        int def = abs(left - right);
        if (def > 1) {
            return -1;
        } else {
            return 1 + max(left ,right);
        }
    }
};

int main() {

    return 0;
}