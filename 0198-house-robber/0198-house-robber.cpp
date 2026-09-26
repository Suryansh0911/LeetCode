class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1) return nums[0];
        int oneBack = max(nums[0], nums[1]);
        int twoBack = nums[0];
        int ans=max(nums[0], nums[1]);
        for(int i=2; i<n; i++){
            ans = max(nums[i] + twoBack, oneBack);
            twoBack = oneBack;
            oneBack = ans;
        }

        return ans;
    }
};