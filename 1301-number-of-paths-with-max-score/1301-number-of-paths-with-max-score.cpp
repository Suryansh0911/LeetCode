class Solution {
public:
    int MOD = 1e9 + 7;
    pair<int, int> memo[105][105];
    bool visited[105][105];

    bool isValid(int r, int c, const vector<string>& board) {
        int n = board.size();
        return (r >= 0 && c >= 0 && r < n && c < n && board[r][c] != 'X');
    }

    pair<int, int> solve(int r, int c, const vector<string>& board) {
        if (r == 0 && c == 0) return {0, 1}; 
        if (visited[r][c]) return memo[r][c];

        int max_s = -1; 
        int ways = 0;

        int dr[] = {-1, 0, -1};
        int dc[] = {0, -1, -1};

        for (int i = 0; i < 3; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (isValid(nr, nc, board)) {
                auto [next_score, next_ways] = solve(nr, nc, board);

                if (next_score != -1) { 
                    int current_val = (board[r][c] == 'S') ? 0 : (board[r][c] - '0');
                    int total_score = next_score + current_val;

                    if (total_score > max_s) {
                        max_s = total_score;
                        ways = next_ways; 
                    } else if (total_score == max_s) {
                        ways = (ways + next_ways) % MOD;
                    }
                }
            }
        }

        visited[r][c] = true;
        return memo[r][c] = {max_s, ways};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        memset(visited, false, sizeof(visited));

        auto [max_score, ways] = solve(n - 1, n - 1, board);

        if (max_score == -1) {
            return {0, 0};
        }
        
        return {max_score, ways};
    }
};