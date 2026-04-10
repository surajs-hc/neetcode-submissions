class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> existing_nums;
        for (int num : nums) {
            if (existing_nums.find(num) != existing_nums.end())
                return true;
            existing_nums.insert(num);
        }
        return false;
    }
};