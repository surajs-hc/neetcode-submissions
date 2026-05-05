class Solution {
private:
    void dfs(const vector<int>& nums, vector<int> builder, vector<vector<int>>& sol, int i, int n) {
        if (i == n) {
            sol.emplace_back(move(builder));
        }
        else {
            dfs(nums, builder, sol, i + 1, n);
            builder.push_back(nums[i]);
            dfs(nums, builder, sol, i + 1, n);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol;
        dfs(nums, vector<int>{}, sol, 0, nums.size());
        return sol;
    }
};
