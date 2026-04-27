class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void dfs(int r, int c, vector<vector<char>> &grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        // mark visited
        grid[r][c] = '0';
        for (int d = 0; d < 4; d++) {
            int nr = r + dir[d][0];
            int nc = c + dir[d][1];
            if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc]=='1'){
                dfs(nr,nc,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans =0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
