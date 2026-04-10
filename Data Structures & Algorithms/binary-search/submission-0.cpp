class Solution {
public:
    int search(vector<int>& nums, int target) {
        int r = 0;
        int l = nums.size() - 1;
        while (r <= l) {
            int m = (r + l) / 2;
            if (nums[m] < target) {
                r = m + 1;
            }
            else if (nums[m] > target) {
                l = m - 1;
            }
            else {
                return m;
            }
        }
        return -1;
    }
};
