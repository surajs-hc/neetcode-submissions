class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> targets;
        for (int i = 0; i < nums.size(); ++i) {
            if (targets.find(nums[i]) == targets.end()) {
                targets[target - nums[i]] = i;
            }
            else {
                return vector<int>{targets[nums[i]], i};
            }
        }

        return vector<int>{-1, -1};
    }
};
