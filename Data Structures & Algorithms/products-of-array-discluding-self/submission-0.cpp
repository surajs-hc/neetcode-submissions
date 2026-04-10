class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProduct;
        vector<int> postfixProduct;
        int prev = 1;
        for (int i = 0; i < nums.size(); ++i) {
            prefixProduct.push_back(prev);
            prev *= nums[i];
        }

        prev = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            postfixProduct.push_back(prev);
            prev *= nums[i];
        }
        reverse(postfixProduct.begin(), postfixProduct.end());

        vector<int> solution;
        for (int i = 0; i < nums.size(); ++i) {
            solution.push_back(prefixProduct[i] * postfixProduct[i]);
        }
        return solution;
    }
};
