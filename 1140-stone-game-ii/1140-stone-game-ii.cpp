class Solution {
public:
    int help(vector<int>&piles, int i, int m, vector<vector<int>> &dp){
        int n = piles.size();
        if (i == n)
            return 0;
        if (n - i <= 2 * m) {
            int sum = 0;
            for (int j = i; j < n; j++)
                sum += piles[j];
            return sum;
        }

        if(dp[i][m] != -1) return dp[i][m];
        int diff = INT_MIN;
        int sum=0, xN=min(2*m, n-i);
        for(int x=1; x<=xN; x++){
            sum += piles[i+x-1];
            diff = max(diff, sum - help(piles, i+x, max(x, m), dp));
        }
        return dp[i][m] = diff;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(101, vector<int>(101, -1));
        int sum = accumulate(piles.begin(), piles.end(), 0);
        return (sum + help(piles, 0, 1, dp))/2;
    }
};