class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<double, int>> heap;
        for (int i = 0; i < points.size(); ++i) {
            const auto& point = points[i];
            heap.push_back(make_pair(sqrt(pow(point[0], 2) + pow(point[1], 2)), i));
        }
        make_heap(heap.begin(), heap.end(), greater<pair<double, int>>{});
        
        vector<vector<int>> solution;
        for (int i = 0; i < k; ++i) {
            const pair<double, int>& point_pair = heap[0];
            solution.emplace_back(points[point_pair.second].begin(), points[point_pair.second].end());
            pop_heap(heap.begin(), heap.end(), greater<pair<double, int>>{});
            heap.pop_back();
        }

        return solution;
    }
};
