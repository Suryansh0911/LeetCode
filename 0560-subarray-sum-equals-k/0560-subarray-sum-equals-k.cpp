class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> frq;
        int ans=0, sum=0;
        frq[0]=1;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(frq.find(sum-k) != frq.end()){
                ans += frq[sum-k];
            }
            frq[sum]++;
        }
        return ans;
    }
};