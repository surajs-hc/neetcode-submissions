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

        vector<pair<int, int>> heap;
        for (const auto [dist, point] : distances[0]) {
            heap.emplace_back(dist, point);
        }
        make_heap(heap.begin(), heap.end(), greater<pair<int, int>>());

        int cost = 0;
        while (!heap.empty()) {
            pop_heap(heap.begin(), heap.end(), greater<pair<int, int>>());
            auto [dist, point] = heap.back();
            heap.pop_back();
            if (!visited[point]) {
                visited[point] = true;

                cost += dist;
                for (const auto [dist, point] : distances[point]) {
                    if (!visited[point]) {
                        heap.emplace_back(dist, point);
                        push_heap(heap.begin(), heap.end(), greater<pair<int, int>>());
                    }
                }
            }
        }
        
        return cost;
    }
};
