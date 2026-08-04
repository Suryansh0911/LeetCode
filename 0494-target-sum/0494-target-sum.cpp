class Solution {
public:
    vector<vector<int>> dp;
    int offset;
    int help(vector<int> &nums, int n, int i, int target){
        if(target < -offset || target > offset) return 0;
        if(i == n) return target==0;

        if(dp[i][target+offset] != -1){
            return dp[i][target+offset];
        }
        
        int add = help(nums, n, i+1, target-nums[i]);
        int sub = help(nums, n, i+1, target+nums[i]);
        return dp[i][target+offset] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target){
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < abs(target)) return 0;
        offset = sum;
        dp.assign(nums.size(), vector<int>(2*sum+1, -1));
        return help(nums, nums.size(), 0, target);
    }
};