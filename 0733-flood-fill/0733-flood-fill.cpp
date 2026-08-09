class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int m, int n, int originalColor) {
        if (sr < 0 || sr >= m || sc < 0 || sc >= n) return;
        if (image[sr][sc] != originalColor) return;
        image[sr][sc] = newColor;
        dfs(image, sr + 1, sc, newColor, m, n, originalColor);
        dfs(image, sr - 1, sc, newColor, m, n, originalColor);
        dfs(image, sr, sc + 1, newColor, m, n, originalColor);
        dfs(image, sr, sc - 1, newColor, m, n, originalColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor != color) {
            int m = image.size();
            int n = image[0].size();
            dfs(image, sr, sc, color, m, n, originalColor);
        }
        return image;
    }
};