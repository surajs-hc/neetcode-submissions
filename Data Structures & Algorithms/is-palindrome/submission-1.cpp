class Solution {
private:
    bool is_numeric(char c) {
        return (c >= '0' && c <= '9');
    }
    bool is_alpha_numeric(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || is_numeric(c);
    }
    bool is_identical(char a, char b) {
        if (is_numeric(a) || is_numeric(b))
            return a == b;
        return (a == b) || (a - 'A' == b - 'a') || (a - 'a' == b - 'A');
    }
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            while (!is_alpha_numeric(s[l]) && l < r) {
                ++l;
            }
            while (!is_alpha_numeric(s[r]) && l < r) {
                --r;
            }
            if (!is_identical(s[l], s[r])) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};
