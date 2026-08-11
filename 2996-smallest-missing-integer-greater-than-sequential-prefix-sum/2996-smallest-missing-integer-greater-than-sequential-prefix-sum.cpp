class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefixsum = nums[0];
        unordered_set<int> s(nums.begin(), nums.end());
        for(int j=1; j<nums.size(); j++){
            if(nums[j] == nums[j-1]+1){
                prefixsum += nums[j];
            }else{
                break;
            }
        }
        while(s.count(prefixsum)){
            prefixsum++;
        }
        return prefixsum;
    }
};