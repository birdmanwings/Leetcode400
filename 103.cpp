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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        levelOrder(root, 0, res);
        int i = 0;
        while (i < res.size()) {
            if (i % 2 == 1) {
                reverse(res[i].begin(), res[i].end());
            }
            i++;
        }
        return res;
    }

    void levelOrder(TreeNode *root, int level, vector<vector<int>> &res) {
        if (!root) {
            return;
        }
        if (res.size() == level) {  //新建每层的数组
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