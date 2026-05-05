class Solution {
private:
    void dfs(const vector<int>& nums, vector<int>& builder, vector<vector<int>>& sol, int target, int i, int n) {
        if (target == 0) {
            sol.emplace_back(builder);
        }
        else if (i < n && target > 0) {
            builder.push_back(nums[i]);
            dfs(nums, builder, sol, target - nums[i], i, n);
            builder.pop_back();
            dfs(nums, builder, sol, target, i + 1, n);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> sol;
        vector<int> builder;
        dfs(nums, builder, sol, target, 0, nums.size());
        return sol;
    }
};
