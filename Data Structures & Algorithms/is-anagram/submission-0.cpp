class Solution {
public:
    bool isAnagram(string s, string t) {
        char characters[26];
        for (int i = 0; i < 26; ++i) {
            characters[i] = 0;
        }

        for (char c : s) {
            ++characters[c - 'a'];
        }

        for (char c : t) {
            --characters[c - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (characters[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
