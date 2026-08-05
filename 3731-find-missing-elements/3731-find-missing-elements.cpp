class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());
        vector<int> ans;
        vector<bool> present(max-min+1, false);
        for(int num : nums){
            present[num-min] = true;
        }

        for(int i=min+1; i<=max; i++){
            if(!present[i-min]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};