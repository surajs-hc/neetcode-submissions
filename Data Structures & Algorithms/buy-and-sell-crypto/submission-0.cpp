class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPtr = 0;
        int sellPtr = 1;
        int profit = 0;

        while (sellPtr < prices.size()) {
            profit = max(profit, prices[sellPtr] - prices[buyPtr]);
            if (prices[sellPtr] < prices[buyPtr]) {
                buyPtr = sellPtr;
            }
            ++sellPtr;
        }

        return profit;
    }
};
