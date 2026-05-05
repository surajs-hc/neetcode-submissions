class Solution {
private:
    void dfs(const vector<int>& nums, vector<vector<int>>& sol, vector<int> builder, int i, int n) {
        if (i >= n) {
            sol.emplace_back(move(builder));
        }
        else {
            builder.push_back(nums[i]);
            dfs(nums, sol, builder, i + 1, n);
            builder.pop_back();

            int k = i + 1;
            while (k < n && nums[k] == nums[i]) {
                ++k;
            }
            dfs(nums, sol, builder, k, n);
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> sol;
        sort(nums.begin(), nums.end());
        dfs(nums, sol, vector<int>{}, 0, nums.size());
        return sol;
    }
};
