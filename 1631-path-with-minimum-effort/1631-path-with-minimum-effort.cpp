class Solution {
public:
    bool valid(int r, int c, int m, int n){
        if(r>=0 && r<=m-1 && c>=0 && c<=n-1){
            return true;
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> ans(m);
        for (int i=0; i<m; i++){
            vector<int> t(n, INT_MAX);
            ans[i] = t;
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};
        ans[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int wt = p.first;
            int row = p.second.first;
            int col = p.second.second;
            if(wt > ans[row][col]) continue;
            for(int k=0; k<4; k++){
                int r = row + x[k];
                int c = col + y[k];
                if(!valid(r, c, m, n)) continue;
                int abdiff = abs(heights[r][c] - heights[row][col]);
                int newwt = max(wt, abdiff);
                if(newwt < ans[r][c]){
                    ans[r][c] = newwt;
                    pq.push({newwt, {r, c}});
                }
            }
        }
        return ans[m-1][n-1];
    }
};