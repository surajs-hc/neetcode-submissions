class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        
        int l_ptr = 0;
        int r_ptr = 1;
        int longest_len = 1;

        unordered_set<char> seen_chars;
        seen_chars.insert(s[0]);

        while (r_ptr < s.size()) {
            if (seen_chars.find(s[r_ptr]) != seen_chars.end()) {
                // duplicate found
                longest_len = max(longest_len, r_ptr - l_ptr);
                while (l_ptr < r_ptr && s[l_ptr] != s[r_ptr]) {
                    seen_chars.erase(s[l_ptr]);
                    ++l_ptr;
                }
                ++l_ptr;
            }
            else {
                seen_chars.insert(s[r_ptr]);
            }
            ++r_ptr;
        }
        longest_len = max(longest_len, r_ptr - l_ptr);

        return longest_len;
    }
};
