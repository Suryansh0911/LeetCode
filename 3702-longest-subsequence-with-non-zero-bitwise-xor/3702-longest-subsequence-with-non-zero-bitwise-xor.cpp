class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int sum=0, n = nums.size();

        bool allzero=1;
        for(int x : nums){
            sum ^= x;
            allzero &= x == 0;
        }
        return (allzero) ? 0 : n - (sum==0);
    }
};