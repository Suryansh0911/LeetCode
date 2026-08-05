class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> count;
        for(int x : nums){
            auto idx = lower_bound(count.begin(), count.end(), x);
            if(idx == count.end()){
                count.push_back(x);
            }else{
                *idx = x;
            }
        }
        return count.size();
    }
};