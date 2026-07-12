class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        int rank = 1;
        unordered_map<int, int> map;

        for(int num : sorted){
            if(map.find(num) == map.end()){
                map[num] = rank;
                rank++;
            }
        }
        vector<int> ans;
        for(int numm : arr){
            ans.push_back(map[numm]);
        }
        return ans;
    }
};