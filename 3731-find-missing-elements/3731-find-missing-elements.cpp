class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());
        vector<int> ans;
        unordered_set<int> s(nums.begin(), nums.end());

        for(int i=min+1; i<=max; i++){
            if(!s.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};