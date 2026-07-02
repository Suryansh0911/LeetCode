class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> min_damage(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;

        min_damage[0][0] = grid[0][0];
        dq.push_front({0, 0});

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!dq.empty()){
            auto [r, c] = dq.front();
            dq.pop_front();
            if(r == m-1 && c == n-1){
                return (health - min_damage[r][c]) >= 1;
            }

            for(auto &d : dirs){
                int nr = r + d[0];
                int nc = c + d[1];
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    int damage = grid[nr][nc];

                    if(min_damage[r][c] + damage < min_damage[nr][nc]){
                        min_damage[nr][nc] = min_damage[r][c] + damage;

                        if(damage == 0){
                            dq.push_front({nr, nc});
                        }else{
                            dq.push_back({nr, nc});
                        }
                    }
                }
            }
        }
        return false;
    }
};