class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= amount; i++){
            for (auto coin : coins){
                if (i-coin >= 0 && dp[i-coin] != INT_MAX){
                    dp[i] = min(dp[i], dp[i-coin]+1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
/*
dp[i] = what is the min amount of coins needed to make amount i?
*/