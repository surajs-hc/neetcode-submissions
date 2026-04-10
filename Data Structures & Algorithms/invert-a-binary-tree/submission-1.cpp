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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }

        deque<TreeNode*> stk;
        stk.push_back(root);

        while (!stk.empty()) {
            TreeNode* node = stk.back();
            stk.pop_back();

            TreeNode* temp = node->right;
            node->right = node->left;
            node->left = temp;

            if (node->right) {
                stk.push_back(node->right);
            }
            if (node->left) {
                stk.push_back(node->left);
            }
        }

        return root;
    }
};
