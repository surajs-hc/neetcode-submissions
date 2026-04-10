class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_water = 0;
        for (int i = 0; i < heights.size(); ++i) {
            for (int j = i + 1; j < heights.size(); ++j) {
                max_water = max(max_water, (j - i) * min(heights[j], heights[i]));
            }
        }
        return max_water;
    }
};
