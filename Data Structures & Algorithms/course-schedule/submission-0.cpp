class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> incomingEdges(numCourses, 0);

        for (const vector<int>& prereq : prerequisites) {
            ++incomingEdges[prereq[1]];
            adj[prereq[0]].push_back(prereq[1]);
        }

        queue<int> nodes;
        for (int node = 0; node < numCourses; ++node) {
            if (incomingEdges[node] == 0) {
                nodes.push(node);
            }
        }

        for (int nodeCounter = 0; nodeCounter < numCourses; ++nodeCounter) {
            if (nodes.empty()) {
                return false;
            }
            int nodeInQ = nodes.front();
            nodes.pop();
            for (int course : adj[nodeInQ]) {
                if (--incomingEdges[course] == 0) {
                    nodes.push(course);
                }
            }
        }
        return true;
    }
};
