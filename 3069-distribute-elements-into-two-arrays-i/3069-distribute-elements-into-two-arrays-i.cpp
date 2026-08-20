class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1, arr2;
        arr1.reserve(n);
        arr2.reserve(n);
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2; i<nums.size(); i++){
            if(arr1.back() > arr2.back()){
                arr1.push_back(nums[i]);
            }else{
                arr2.push_back(nums[i]);
            }
        }
        vector<int> res;
        res.reserve(n);
        res.insert(res.end(), arr1.begin(), arr1.end());
        res.insert(res.end(), arr2.begin(), arr2.end());
        return res;
        
    }
};