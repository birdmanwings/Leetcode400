#include <iostream>
#include <vector>
#include <unordered_map>

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
    vector<vector<int>> findLeaves(TreeNode *root) {
        vector<vector<int>> res;
        while (root) {
            vector<int> leaves;
            root = remove(root, leaves);
            res.push_back(leaves);
        }
        return res;
    }

    TreeNode *remove(TreeNode *node, vector<int> &leaves) {
        if (!node) {
            return NULL;
        }
        if (!node->left && !node->right) {
            leaves.push_back(node->val);
            return NULL;
        }
        node->left = remove(node->left, leaves);
        node->right = remove(node->right, leaves);
        return node;
    }
};

int main() {

    return 0;
}