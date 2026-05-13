class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> solution;
        
        for (int i = 0, n = nums.size(); i <= n - k; ++i) {
            int maxNum = nums[i];
            for (int j = i + 1; j < i + k; ++j) {
                maxNum = max(maxNum, nums[j]);
            }
            solution.push_back(maxNum);
        }


        return solution;
    }
};
