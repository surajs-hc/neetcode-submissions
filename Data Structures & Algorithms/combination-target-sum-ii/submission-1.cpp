class Solution {
private:
    void dfs(const vector<int>& candidates, vector<int>& builder, vector<vector<int>>& sol, int target, int i, int n) {
        if (target == 0) {
            sol.emplace_back(builder);
        }
        else if (i < n && target > 0) {
            builder.push_back(candidates[i]);
            dfs(candidates, builder, sol, target - candidates[i], i + 1, n);
            builder.pop_back();

            int k = i + 1;
            while (k < n && candidates[k] == candidates[i]) {
                ++k;
            }
            dfs(candidates, builder, sol, target, k, n);
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> sol;
        vector<int> builder;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, builder, sol, target, 0, candidates.size());

        return sol;
    }
};
