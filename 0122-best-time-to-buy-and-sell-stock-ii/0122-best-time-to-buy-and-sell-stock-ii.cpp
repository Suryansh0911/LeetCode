class Solution {
public:
    int help(vector<vector<int>> &dp, vector<int> &prices, int i, int k){
        if(i == prices.size()) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        if(k){
            int c1 = help(dp, prices, i+1, k-1) - prices[i];
            int c2 = help(dp, prices, i+1, k);
            return dp[i][k] = max(c1, c2);
        }
        int c1 = help(dp, prices, i+1, k+1) + prices[i];
        int c2 = help(dp, prices, i+1, k);
        return dp[i][k] = max(c1, c2);

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return help(dp, prices, 0, 1);
    }
};