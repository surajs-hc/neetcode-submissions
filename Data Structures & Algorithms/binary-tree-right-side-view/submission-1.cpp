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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> solution;
        if (!root) {
            return solution;
        }

        deque<TreeNode*> nodes;
        nodes.push_back(root);
        while (!nodes.empty()) {
            int num_nodes = nodes.size();
            solution.push_back(nodes.front()->val);
            for (int i = 0; i < num_nodes; ++i) {
                TreeNode* node = nodes.front();
                nodes.pop_front();

                if (node->right) {
                    nodes.push_back(node->right);
                }
                if (node->left) {
                    nodes.push_back(node->left);
                }
            }
        }
        
        return solution;
    }
};
