class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> runsum(nums.size());
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            runsum[i] = sum;
        }
        return runsum;
    }
};