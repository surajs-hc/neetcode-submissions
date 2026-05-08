class Solution {
private:
    void findCombinations(vector<string>& combinations, unordered_map<char, vector<char>>& mapping, const string& digits, string& builder, int i, int n) {
        if (i == n) {
            combinations.emplace_back(builder);
        }
        else {
            for (char character : mapping[digits[i]]) {
                builder.push_back(character);
                findCombinations(combinations, mapping, digits, builder, i + 1, n);
                builder.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return vector<string>{};
        }

        unordered_map<char, vector<char>> mapping = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };
        
        vector<string> combinations;
        string builder = "";
        findCombinations(combinations, mapping, digits, builder, 0, digits.size());
        return combinations;
    }
};
