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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        levelOrder(root, 0, res);
        return vector<vector<int>>(res.rbegin(), res.rend());
    }

    void levelOrder(TreeNode *root, int level, vector<vector<int>> &res) {
        if (!root) {
            return;
        }
        if (res.size() == level) {
            res.push_back({});
        }
        res[level].push_back(root->val);
        if (root->left) {
            levelOrder(root->left, level + 1, res);
        }
        if (root->right) {
            levelOrder(root->right, level + 1, res);
        }
    }
};

int main() {

    return 0;
}