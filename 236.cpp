#include <iostream>
#include <vector>
#include <climits>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || p == root || q == root) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        if (left && left != p && left != q) return left;
        TreeNode *right = lowestCommonAncestor(root->right, p , q);
        if (left && right) return root;
        return left ? left : right;

    }
};

int main() {
    string s = "a", t = "b";
    Solution S;
    S.isAnagram(s, t);
    return 0;
}