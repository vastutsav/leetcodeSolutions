class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold = -prices[0];
        int cash = 0;
        for (auto itr = prices.begin(); itr != prices.end(); itr++){
            cash = max(cash, hold + *itr - fee);
            hold = max(hold, cash - *itr);
        }
        return cash;
    }
};