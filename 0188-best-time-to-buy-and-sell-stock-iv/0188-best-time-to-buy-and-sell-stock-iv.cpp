class Solution {
public:
    int help(vector<vector<int>> &dp, vector<int> &prices, int i, int k){
        if(i == prices.size() || k==0) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        if(k%2 == 0){
            int buy = help(dp, prices, i+1, k-1) - prices[i];
            int skip = help(dp, prices, i+1, k);
            return dp[i][k] = max(buy, skip);
        }
        int sell = help(dp, prices, i+1, k-1) + prices[i];
        int skip = help(dp, prices, i+1, k);
        return dp[i][k] = max(sell, skip);

    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        k*=2;
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return help(dp, prices, 0, k);
    }
};