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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return vector<vector<int>>{};
        }

        vector<vector<int>> solution;
        deque<TreeNode*> nodes;
        nodes.push_back(root);
        while (!nodes.empty()) {
            deque<TreeNode*> layer;
            vector<int> layer_vec;
            layer_vec.reserve(nodes.size());

            while(!nodes.empty()) {
                TreeNode* node = nodes.front();
                layer_vec.push_back(node->val);
                nodes.pop_front();
                if (node->left) {
                    layer.push_back(node->left);
                }
                if (node->right) {
                    layer.push_back(node->right);
                }
            }
            
            solution.push_back(move(layer_vec));
            nodes = move(layer);
        }

        return solution;
    }
};
