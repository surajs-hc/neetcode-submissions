class Solution {
private:
    void addPermutations(vector<vector<int>>& sol, const vector<int>& vec, int num) {
        vector<int> temp;
        for (int i = 0; i < vec.size(); ++i) {
            temp.clear();
            for (int k = 0; k < vec.size(); ++k) {
                if (k == i) {
                    temp.push_back(num);
                }
                temp.push_back(vec[k]);
            }

            sol.emplace_back(temp);
        }
        temp = vec;
        temp.push_back(num);
        sol.emplace_back(temp);

        // for (int i = 0; i <= vec.size(); ++i) {
        //     vector<int> temp = vec; 
        //     temp.insert(temp.begin() + i, num);
        //     sol.emplace_back(move(temp));
        // }
    }

    vector<vector<int>> computePermutations(const vector<int>& nums, int i, int n) {
        if (i == n) {
            return {{}};
        }
        vector<vector<int>> prev = computePermutations(nums, i + 1, n);
        int curr = nums[i];
        
        vector<vector<int>> sol;
        for (const vector<int>& v : prev) {
            addPermutations(sol, v, curr);
        }
        return sol;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return computePermutations(nums, 0, nums.size());
    }
};
