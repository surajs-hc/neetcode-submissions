class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        for (int section = 0; section < height.size(); ++section) {
            int lHeight = 0;
            int rHeight = 0;
            for (int l = section - 1; l >= 0; --l) {
                lHeight = max(lHeight, height[l]);
            }
            for (int r = section + 1; r < height.size(); ++r) {
                rHeight = max(rHeight, height[r]);
            }
            water += max(0, min(lHeight, rHeight) - height[section]);
        }
        return water;
    }
};
