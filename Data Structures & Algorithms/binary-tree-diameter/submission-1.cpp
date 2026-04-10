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
    pair<int, int> maxDiam(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        pair<int, int> left = maxDiam(root->left);
        pair<int, int> right = maxDiam(root->right);
        int maxDiam = max(max(left.first, right.first), 1 + left.second + right.second);
        int maxPath = 1 + max(left.second, right.second);
        return {maxDiam, maxPath};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return maxDiam(root).first - 1;
    }
};
