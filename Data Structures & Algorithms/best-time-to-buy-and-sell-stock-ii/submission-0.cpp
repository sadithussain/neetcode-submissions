class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int price = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < price) {
                price = prices[i];
            }
            else {
                ans += prices[i] - price;
                price = prices[i];
            }
        }
        return ans;
    }
};