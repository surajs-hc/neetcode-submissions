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
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, make_pair(-1001, 1001));
    }

    bool helper(TreeNode* root, pair<int, int> bounds) {
        if (!root) {
            return true;
        }
        if (bounds.first >= root->val || bounds.second <= root->val) {
            return false;
        }
        return helper(root->left, make_pair(bounds.first, root->val)) && helper(root->right, make_pair(root->val, bounds.second));
    }
};
