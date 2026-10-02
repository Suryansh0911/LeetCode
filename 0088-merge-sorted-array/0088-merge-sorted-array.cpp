class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int id = m+n-1, i=m-1, j=n-1;
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[id] = nums1[i];
                id--; i--;
            }else{
                nums1[id] = nums2[j];
                id--; j--;
            }
        }
        while(j>=0){
            nums1[id] = nums2[j];
            id--; j--;
        }
    }
};