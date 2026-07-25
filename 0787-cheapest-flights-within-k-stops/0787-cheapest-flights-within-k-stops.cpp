class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> ans(n, 1e8);
        ans[src] = 0;
        vector<int> temp = ans;
        for(int i=0; i<k+1; i++){
            for(int j=0; j<flights.size(); j++){
                int s = flights[j][0];
                int d = flights[j][1];
                int w = flights[j][2];
                if(ans[s] != 1e8 && temp[d] > ans[s] + w){
                    temp[d] = ans[s] + w;
                }
            }
            ans = temp;
        }
        if(ans[dst] == 1e8) return -1;
        return ans[dst];
    }
};