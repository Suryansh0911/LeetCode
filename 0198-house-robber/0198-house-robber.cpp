class Solution {
public:
    vector<int> dp;
    int help(vector<int> &nums, int i){
        if(i==0) return nums[0];
        if(i==1) return max(nums[0], nums[1]);
        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + help(nums, i-2);
        int leave = help(nums, i-1);
        return dp[i] = max(pick, leave);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1);
        return help(nums, n-1);
    }
};