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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (true) {
            int rval = root->val;
            int pval = p->val;
            int qval = q->val;
            int low = min(pval, qval);
            int high = max(pval, qval);

            if (rval > high) {
                root = root->left;
            }
            else if (rval < low) {
                root = root->right;
            }
            else {
                return root;
            }
        }
    }
};
