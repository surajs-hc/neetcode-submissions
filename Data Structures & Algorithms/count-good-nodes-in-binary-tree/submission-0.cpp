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
    int dfs(TreeNode* root, int highestPrev) {
        if (!root) {
            return 0;
        }
        int addition = 0;
        if (root->val >= highestPrev) {
            addition = 1;
        }
        highestPrev = max(highestPrev, root->val);
        return addition + dfs(root->right, highestPrev) + dfs(root->left, highestPrev);
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, -101);
    }
};
