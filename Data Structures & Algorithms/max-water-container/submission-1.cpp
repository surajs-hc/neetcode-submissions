class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_water = 0;
        int lPtr = 0;
        int rPtr = heights.size() - 1;
        while (lPtr < rPtr) {
            max_water = max(max_water, (rPtr - lPtr) * min(heights[rPtr], heights[lPtr]));
            if (heights[rPtr] < heights[lPtr]) {
                --rPtr;
            }
            else {
                ++lPtr;
            }
        }
        return max_water;
    }
};
