class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> solution(n, 1);

        for (int i = 1; i < n; ++i) {
            solution[i] = solution[i - 1] * nums[i - 1];
        }

        int running_postfix = 1;
        for (int i = n - 1; i >= 0; --i) {
            solution[i] *= running_postfix;
            running_postfix *= nums[i];
        }
        // 1 1 2 8
        // 
        return solution;
    }
};
