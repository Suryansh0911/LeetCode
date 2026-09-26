class Solution {
    vector<int> dp;
    int ways(int i){
        if(i<=1) return 1;
        if(dp[i] != -1) return dp[i];
        return dp[i] = ways(i-1) + ways(i-2);
    }
public:
    
    int climbStairs(int n) {
        dp.assign(n+1, -1);
        return ways(n);
    }
};