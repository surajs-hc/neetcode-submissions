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

class Solution {
private:
    // first is diam, second is path
    pair<int, int> dfs(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        int max_diameter = max(max(left.first, right.first), 1 + left.second + right.second);
        int max_path = 1 + max(left.second, right.second); 
        return {max_diameter, max_path};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return dfs(root).first - 1;
    }
};
