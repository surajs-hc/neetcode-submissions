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

typedef pair<TreeNode*, int> elem;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int maxD = 0;
        deque<elem> stk;
        stk.push_back({root, 1});
        while (!stk.empty()) {
            elem e = stk.front();
            stk.pop_front();

            maxD = max(maxD, e.second);
            if (e.first->left) {
                stk.push_back({e.first->left, e.second + 1});
            }
            if (e.first->right) {
                stk.push_back({e.first->right, e.second + 1});
            }
        }
        return maxD;
    }
};
