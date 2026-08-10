class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int sum=0, ans=0;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            int rem = sum - k;
            if(map.find(rem) != map.end()){
                ans += map[rem];
            }
            map[sum]++;
        }
        return ans;
    }
};