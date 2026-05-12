class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26, 0);
        
        int n = ransomNote.size();
        for (char c : ransomNote) {
            count[c - 'a']++;
        }

        for (char c : magazine) {
            if (count[c - 'a'] > 0) {
                --count[c - 'a'];
                --n;
            }
        }

        return n == 0;
    }
};