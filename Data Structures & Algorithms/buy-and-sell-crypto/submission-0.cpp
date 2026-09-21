class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minBuy = prices[0];
        for (auto p : prices){
            maxProfit = max(maxProfit, p-minBuy);
            minBuy = min(minBuy, p);

        }
        return maxProfit;
    }
};
