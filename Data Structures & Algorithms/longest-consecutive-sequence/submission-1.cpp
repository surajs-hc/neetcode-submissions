class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set;
        for (const auto num : nums) {
            nums_set.insert(num);
        }

        int max_len = 0;
        for (auto num : nums) {
            if (nums_set.find(num - 1) != nums_set.end()) {
                continue;
            }
            int length = 1;
            ++num;
            while (nums_set.find(num) != nums_set.end()) {
                ++length;
                ++num;
            }
            max_len = max(max_len, length);
        }

        return max_len;
    }
};