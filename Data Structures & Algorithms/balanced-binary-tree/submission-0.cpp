/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

using result = pair<bool, int>;

class Solution {
private:
    result dfs(TreeNode* root) {
        if (!root) {
            return {true, 0};
        }

        result left = dfs(root->left);
        result right = dfs(root->right);

        return {left.first && right.first && abs(left.second - right.second) <= 1, 1 + max(left.second, right.second)};
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
};
