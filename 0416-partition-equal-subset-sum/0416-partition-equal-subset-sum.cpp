class Solution {
public:
    vector<vector<int>> dp;
    bool help(vector<int>& nums, int i, int target){
        if(target == 0) return true;
        if(i >= nums.size() || target < 0) return false;

        if(dp[i][target] != -1) return dp[i][target];

        bool pick = help(nums, i+1, target - nums[i]);
        bool skip = help(nums, i+1, target);

        return dp[i][target] = pick || skip;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int x : nums){
            sum += x;
        }
        if(sum % 2 != 0) return false;
        int target = sum/2;
        if(dp.empty()){
            dp.assign(n, vector<int>(target+1, -1));
        }
        return help(nums, 0, target);
    }
};