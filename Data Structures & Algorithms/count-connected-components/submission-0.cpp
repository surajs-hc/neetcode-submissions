class Solution {
private:
    void markConnectedNodes(const vector<vector<int>>& adjList, vector<bool>& visited, int node) {
        queue<int> q;
        q.push(node);

        while (!q.empty()) {
            int currNode = q.front();
            q.pop();

            for (int edgeNode : adjList[currNode]) {
                if (!visited[edgeNode]) {
                    visited[edgeNode] = true;
                    q.push(edgeNode);
                }
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (const vector<int>& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int connectedComponents = 0;
        for (int node = 0; node < n; ++node) {
            if (!visited[node]) {
                visited[node] = true;
                markConnectedNodes(adjList, visited, node);
                ++connectedComponents;
            }
        }
        
        return connectedComponents;
    }
};
