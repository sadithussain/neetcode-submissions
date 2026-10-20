class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_index = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < prices[min_index]) {
                min_index = i;
            }
            max_profit = max(max_profit, prices[i] - prices[min_index]);
        }
        return max_profit;
    }
};
