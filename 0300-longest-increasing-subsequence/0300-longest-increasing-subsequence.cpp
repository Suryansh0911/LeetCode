class Solution {
public:
    vector<vector<int>> dp;
    int help(vector<int>&nums, int i, int prev){
        if(i == nums.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int pick=0;
        if(prev == -1 || nums[prev] < nums[i]){
            pick = 1 + help(nums, i+1, i);
            int skip = help(nums, i+1, prev);
            return dp[i][prev+1] = max(pick, skip);
        }
        return dp[i][prev+1] = help(nums, i+1, prev);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(n+1, -1));
        return help(nums, 0, -1);
    }
};