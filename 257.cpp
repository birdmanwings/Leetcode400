#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) {
            return {};
        }
        if (!root->left && !root->right) return {to_string(root->val)};
        vector<string> left = binaryTreePaths(root->left);
        vector<string> right = binaryTreePaths(root->right);
        left.insert(left.end(), right.begin(), right.end());
        for (auto &a:left) {
            a=to_string(root->val)+"->"+a;
        }
        return left;
    }
};

int main() {
    return 0;
}