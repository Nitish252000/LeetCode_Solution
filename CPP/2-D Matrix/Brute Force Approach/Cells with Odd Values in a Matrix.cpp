class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> mat(m, vector<int>(n, 0));
        for (auto ind : indices) {
            int row = ind[0];
            int col = ind[1];
            // rows
            for (int j = 0; j < n; j++) {
                mat[row][j]++;
            }
            // Cols
            for (int i = 0; i < m; i++) {
                mat[i][col]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] % 2 == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
