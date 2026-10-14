class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto itr = lower_bound(nums.begin(), nums.end(), target);
        return itr - nums.begin();
    }
};