class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int sum=0, best=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            sum = max(nums[i], sum+nums[i]);
            best = max(sum, best);
            if(sum<0) sum=0;
        }
        return best;
    }
};