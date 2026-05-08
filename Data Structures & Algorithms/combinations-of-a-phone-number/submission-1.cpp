class Solution {
private:
    void findCombinations(vector<string>& combinations, vector<string>& mapping, const string& digits, string& builder, int i, int n) {
        if (i == n) {
            combinations.emplace_back(builder);
        }
        else {
            for (char character : mapping[digits[i] - '1']) {
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

        vector<string> mapping = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> combinations;
        string builder = "";
        findCombinations(combinations, mapping, digits, builder, 0, digits.size());
        return combinations;
    }
};
