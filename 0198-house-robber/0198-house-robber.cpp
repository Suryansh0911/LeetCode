class Solution {
public:
    vector<int> dp;
    int help(vector<int> &nums, int i){
        if(i>=nums.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + help(nums, i+2);
        int leave = help(nums, i+1);
        return dp[i] = max(pick, leave);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(dp.empty()){
            dp.assign(n+1, -1);
        }
        return help(nums, 0);
    }
};