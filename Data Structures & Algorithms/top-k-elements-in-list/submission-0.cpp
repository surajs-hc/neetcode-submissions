class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // maps numbers to their frequencies
        unordered_map<int, int> number_frequencies;
        for (int i = 0; i < nums.size(); ++i) {
            ++number_frequencies[nums[i]];
        }

        // bucket[i] contains numbers that appear i times in nums
        vector<vector<int>> buckets(nums.size());
        for (const auto& kv_pair : number_frequencies) {
            // cout << kv_pair.first << " " << kv_pair.second << endl;
            buckets[kv_pair.second - 1].push_back(kv_pair.first);
        }

        vector<int> solution;
        for (int i = buckets.size() - 1; i >= 0 && k > 0; --i) {
            for (int j = 0; j < buckets[i].size() && k > 0; ++j) {
                solution.push_back(buckets[i][j]);
                --k;
            }
        }
        return solution;
    }
};
