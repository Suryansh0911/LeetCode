class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int sum=0, ans=0;
        count[0] = 1;
        for(int x : nums){
            sum += x;
            int rem = ((sum % k) + k ) % k;
            ans += count[rem];
            count[rem]++;
        }
        return ans;
    }
};