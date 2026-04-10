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
        for (const auto& token : tokens) {
            if (token == "+") {
                int opOne = stk.back();
                stk.pop_back();
                int opTwo = stk.back();
                stk.pop_back();
                stk.push_back(opTwo + opOne);
            }
            else if (token == "-") {
                int opOne = stk.back();
                stk.pop_back();
                int opTwo = stk.back();
                stk.pop_back();
                stk.push_back(opTwo - opOne);
            }
            else if (token == "*") {
                int opOne = stk.back();
                stk.pop_back();
                int opTwo = stk.back();
                stk.pop_back();
                stk.push_back(opTwo * opOne);
            }
            else if (token == "/") {
                int opOne = stk.back();
                stk.pop_back();
                int opTwo = stk.back();
                stk.pop_back();
                stk.push_back(opTwo / opOne);
            }
            else {
                stk.push_back(stoi(token));
            }
        }

        return stk.back();
    }
};
