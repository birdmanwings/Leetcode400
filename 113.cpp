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
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> out;
        helper(root, sum, out, res);
        return res;
    }

    void helper(TreeNode *node, int sum, vector<int>& out, vector<vector<int>>& res) {
        if(!node) {
            return;
        }
        out.push_back(node->val);
        if (!node->left && !node->right && node->val == sum) {
            res.push_back(out);
        }
        helper(node->left, sum - node->val, out, res);
        helper(node->right, sum - node->val, out, res);
        out.pop_back();
    }
};

int main() {

    return 0;
}