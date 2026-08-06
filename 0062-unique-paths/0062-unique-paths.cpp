class Solution {
public:
    int help(vector<vector<int>> &dp, int m, int n, int i, int j){
        if(i == m-1 && j == n-1) return 1;
        if(i>0 && i>=m || j>0 && j>=n) return 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = help(dp, m, n, i+1, j) + help(dp, m, n, i, j+1);
    }
    int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
       dp[m-1][n-1] = 1;
       return help(dp, m, n, 0, 0); 
    }
};