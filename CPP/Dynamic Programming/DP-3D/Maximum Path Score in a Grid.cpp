class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> dp(
            rows, vector<vector<int>>(cols, vector<int>(k+1, INT_MIN)));

        dp[0][0][0] = 0; // dp[i][j][c] = max score reaching (i,j) using c cost

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int c = 0; c <= k; c++) {
                    if (dp[i][j][c] == INT_MIN)
                        continue;

                    if (i + 1 < rows) {
                        int val = grid[i + 1][j];
                        int cost = (val == 0 ? 0 : 1);
                        if (c + cost <= k)
                            dp[i + 1][j][c+cost] =
                                max(dp[i][j][c] + val, dp[i + 1][j][c + cost]);
                    }
                    if (j + 1 < cols) {
                        int val = grid[i][j + 1];
                        int cost = (val == 0 ? 0 : 1);
                        if (c + cost <= k)
                            dp[i][j + 1][c+cost] =
                                max(dp[i][j][c] + val, dp[i][j + 1][c + cost]);
                    }
                }
            }
        }
        int ans = INT_MIN;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[rows - 1][cols - 1][c]);
        }
        return ans <0 ? -1 : ans;
    }
};
