/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return node;
        }

        queue<Node*> oldToDuplicate;
        unordered_map<Node*, Node*> oldToNew;
        
        oldToDuplicate.push(node);
        while (!oldToDuplicate.empty()) {
            Node* n = oldToDuplicate.front();
            oldToDuplicate.pop();

            if (oldToNew.find(n) == oldToNew.end()) {
                oldToNew[n] = new Node(n->val);
            }

            for (Node* neighbor : n->neighbors) {
                if (oldToNew.find(neighbor) == oldToNew.end()) {
                    oldToDuplicate.push(neighbor);
                }
            }
        }

        for (auto const& [oldNode, newNode] : oldToNew) {
            for (Node* neighbor : oldNode->neighbors) {
                newNode->neighbors.push_back(oldToNew[neighbor]);
            }
        }

        return oldToNew[node];
    }
};
