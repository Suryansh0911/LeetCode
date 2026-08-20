class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        for(int i=0; i<n; i++){
            map[nums[i]]++;
        }
        if(k == n){
            return *max_element(nums.begin(), nums.end());
        }
        if(k == 1){
            int maxval=-1;
            for(int i=0; i<n; i++){
                if(map[nums[i]] == 1 && nums[i] > maxval){
                    maxval = nums[i];
                }
            }
            return maxval;
        }
        if(nums[0] == nums[n-1]){
            return -1;
        }
        if(map[nums[0]] == 1 && map[nums[n-1]] == 1){
            return max(nums[0], nums[n-1]);
        }
        if(map[nums[0]] == 1 && map[nums[n-1]] > 1){
            return nums[0];
        }
        if(map[nums[n-1]] == 1 && map[nums[0]] > 1){
            return nums[n-1];
        }
        return -1;
    }
};