class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<int> pairXor(2048, 0);
        vector<int> tripletXor(2048, 0);

        for(int i=0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
                pairXor[nums[i] ^ nums[j]] = 1;
            }
        }
        for(int u=0; u<2048; u++){
            if(pairXor[u] == 1){
                for(int v : nums){
                    tripletXor[u ^ v] = 1;
                }
            }
        }
        int cnt=0;
        for(int i=0; i<2048; i++){
            if(tripletXor[i] == 1) cnt++;
        }
        return cnt;
    }
};