class Solution {
public:
    int help(vector<int> &coins, int amount, int i, vector<vector<int>>&dp){
        if(i>=coins.size() || amount<=0) return (amount==0) ? 0 : INT_MAX-1;
        if(dp[i][amount] != -1) return dp[i][amount];
        int take=INT_MAX-1;
        if (coins[i] <= amount) {
            take = 1 + help(coins, amount - coins[i], i, dp); 
        }
        int skip = help(coins, amount, i + 1, dp);
        return dp[i][amount] = min(take, skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int ans = help(coins, amount, 0, dp);
        return (ans == INT_MAX-1) ? -1 : ans;
    }
};