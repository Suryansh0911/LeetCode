class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int totalcells = m*n;
        k = k % totalcells;
        vector<vector<int>> newgrid(m, vector<int>(n));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int oldidx = i*n + j;
                int newidx = (oldidx + k) % totalcells;
                int newrow = newidx/n;
                int newcol = newidx%n;
                newgrid[newrow][newcol] = grid[i][j];
            }
        }
        return newgrid;
    }
};