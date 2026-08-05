class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 1);

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    count[i] = max(count[i], count[j] +1);
                }
            }
        }
        int ans=1;
        for(int cnt : count){
            ans = max(ans, cnt);
        }
        return ans;
    }
};