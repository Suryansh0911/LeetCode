class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd(nums.size());
        int mx=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int left=0, right=prefixGcd.size()-1;
        long long sum=0;
        while(left<right){
            sum += gcd(prefixGcd[left], prefixGcd[right]);
            left++; right--;
        }
        return sum;
    }
};