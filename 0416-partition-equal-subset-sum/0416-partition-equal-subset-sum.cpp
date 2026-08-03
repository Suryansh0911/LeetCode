class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum=accumulate(nums.begin(),nums.end(),0);
        if(total_sum%2!=0)return false;
        int tar=total_sum/2;
        bitset<10001>bs;
        bs[0]=1;
        for(auto ele : nums){
            bs|=bs<<ele;
        }
   return bs[tar]; }
};