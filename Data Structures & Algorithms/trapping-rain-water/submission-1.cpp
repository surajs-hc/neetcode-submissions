class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> tallestFromLeft(n, 0);
        for (int i = 1; i < n; ++i) {
            tallestFromLeft[i] = max(tallestFromLeft[i - 1], height[i - 1]);
        }

        int water = 0;
        int tallestEncountered = 0;
        for (int section = n - 1; section >= 0; --section) {
            water += max(0, min(tallestEncountered, tallestFromLeft[section]) - height[section]);
            tallestEncountered = max(height[section], tallestEncountered);
        }

        return water;
    }
};
