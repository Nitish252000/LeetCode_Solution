class Solution {
public:
    // Right, Bottom, left, Top
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    long long dfs(int r, int c, vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        long long sum = grid[r][c];
        grid[r][c] = 0; // Mark Visited
        for (int d = 0; d < 4; d++) {
            int nr = r + dir[d][0];
            int nc = c + dir[d][1];

            if(nr>=0 && nc>=0 && nr<rows && nc<cols && grid[nr][nc]!=0){
                sum=(sum+dfs(nr,nc,grid,k))%k;
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans =0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != 0) {
                    int total = dfs(i, j, grid, k);
                    if ( total% k==0) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
