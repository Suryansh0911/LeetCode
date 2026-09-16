class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> map;
        int count0=0, count1=0, ans=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) count0++;
            if(nums[i] == 1) count1++;
            int diff = count1 - count0;
            if(diff == 0){
                ans = max(ans, i+1);
            }
            if(map.find(diff) == map.end()){
                map[diff] = i;
            }else{
                int idx = map[diff];
                int len = i - idx;
                ans = max(ans, len);
            }
        }
        return ans;
    }
};