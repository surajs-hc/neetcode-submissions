class Solution {
private:
    bool noCycles(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& parent, int node) {
        queue<int> nodes;
        nodes.push(node);
        visited[node] = true;

        while (!nodes.empty()) {
            int currNode = nodes.front();
            nodes.pop();

            for (int edgeNode : adj[currNode]) {
                if (parent[currNode] == edgeNode) {
                    continue;
                }
                if (visited[edgeNode]) {
                    return false;
                }
                parent[edgeNode] = currNode;
                visited[edgeNode] = true;
                nodes.push(edgeNode);
            }
        }
        
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        vector<int> parent(n, -1);
        for (const vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        if (!noCycles(adj, visited, parent, 0)) {
            return false;
        }
        
        for (bool nodeVisited : visited) {
            if (!nodeVisited) {
                return false;
            }
        }
        return true;
    }
};
