class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        /*
        1. binary operators only
        2. multiple numbers or multiple operations in order
        3. assume polish notation is already validated
        */

        deque<int> stk;
        // plus<int>, minus, multiplies, divides
        unordered_map<string, function<int(int, int)>> functions {
            {"+", plus<int>()},
            {"-", minus<int>()},
            {"*", multiplies<int>()},
            {"/", divides<int>()}
        };
        for (const auto& token : tokens) {
            if (functions.find(token) != functions.end()) {
                int opTwo = stk.back();
                stk.pop_back();
                int opOne = stk.back();
                stk.pop_back();
                stk.push_back(functions[token](opOne, opTwo));
            }
            else {
                stk.push_back(stoi(token));
            }
        }

        return stk.back();
    }
};
