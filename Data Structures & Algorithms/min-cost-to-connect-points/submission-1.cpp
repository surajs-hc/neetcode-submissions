class Solution {
private:
    int manhattan(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> distances(n);

        // build graph
        for (int i = 0; i < n; ++i) {
            for (int k = i + 1; k < n; ++k) {
                int dist = manhattan(points[i], points[k]);
                distances[i].emplace_back(dist, k);
                distances[k].emplace_back(dist, i);
            }
        }

        vector<bool> visited(n, false);
        visited[0] = true;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (const auto [dist, point] : distances[0]) {
            heap.emplace(dist, point);
        }

        int cost = 0;
        while (!heap.empty()) {
            auto [dist, point] = heap.top();
            heap.pop();
            if (!visited[point]) {
                visited[point] = true;

                cost += dist;
                for (const auto [dist, point] : distances[point]) {
                    if (!visited[point]) {
                        heap.emplace(dist, point);
                    }
                }
            }
        }
        
        return cost;
    }
};
