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
    int dfs(TreeNode* node, int& k) {
        if (!node) {
            return -1;
        }
        int result_left = dfs(node->left, k);
        if (result_left != -1) {
            return result_left;
        }
        if (k == 1) {
            return node->val;
        }
        --k;
        return dfs(node->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root, k);
    }
};
