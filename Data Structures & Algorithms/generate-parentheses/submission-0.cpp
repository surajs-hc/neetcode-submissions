class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string builder = "";
        vector<string> result;

        pBuilder(result, n, n, builder);
        return result;
    }


    void pBuilder(vector<string>& resultStore, int open, int close, string& builder) {
        if (open == 0 && close == 0) {
            resultStore.push_back(builder);
            return;
        }
        if (open > 0) {
            builder.push_back('(');
            pBuilder(resultStore, open - 1, close, builder);
            builder.pop_back();
        }
        if (close > open) {
            builder.push_back(')');
            pBuilder(resultStore, open, close - 1, builder);
            builder.pop_back();
        }
    }
};
