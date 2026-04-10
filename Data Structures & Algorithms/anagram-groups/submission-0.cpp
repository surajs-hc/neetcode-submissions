class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> buckets;
        
        for (const auto& str : strs) {
            int char_count[26];
            for (int i = 0; i < 26; ++i) {
                char_count[i] = 0;
            }

            for (const char c : str) {
                char_count[c - 'a']++;
            }

            string hash_key = "";
            for (const int c : char_count) {
                hash_key += c;
            }

            buckets[hash_key].emplace_back(str);
        }

        vector<vector<string>> anagram_groups;
        for (const auto& kv_pair : buckets) {
            anagram_groups.push_back(kv_pair.second);
        }

        return anagram_groups;
    }
};
