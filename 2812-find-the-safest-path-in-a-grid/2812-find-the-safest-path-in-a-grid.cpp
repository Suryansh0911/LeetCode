class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;
        vector<vector<int>> safeness(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    safeness[i][j] = 0;
                }
            }
        }

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && safeness[nr][nc] == -1) {
                    safeness[nr][nc] = safeness[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }


        int low = 0, high = 2 * n;
        int ans = 0;

        auto isValid = [&](int threshold) {

            if (safeness[0][0] < threshold || safeness[n - 1][n - 1] < threshold) return false;

            vector<vector<bool>> visited(n, vector<bool>(n, false));
            queue<pair<int, int>> bfsQ;
            
            bfsQ.push({0, 0});
            visited[0][0] = true;

            while (!bfsQ.empty()) {
                auto [r, c] = bfsQ.front();
                bfsQ.pop();

                if (r == n - 1 && c == n - 1) return true;

                for (auto& d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n 
                        && !visited[nr][nc] && safeness[nr][nc] >= threshold) {
                        visited[nr][nc] = true;
                        bfsQ.push({nr, nc});
                    }
                }
            }
            return false;
        };


        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};