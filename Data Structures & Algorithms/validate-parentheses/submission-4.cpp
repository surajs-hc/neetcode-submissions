class Solution {
public:
    bool isValid(string s) {
        deque<int> stk;
        unordered_map<char, char> openers {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for (const char c : s) {
            if (openers.find(c) == openers.end()) {
                stk.push_back(c);
            }
            else {
                if (stk.empty() || stk.back() != openers[c]) {
                    return false;
                }
                stk.pop_back();
            }
        }

        return stk.empty();
    }
};
