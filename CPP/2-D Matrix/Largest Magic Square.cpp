class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c, int k) {

        // reference sum: first row
        int target = 0;
        for (int j = c; j < c + k; j++) {
            target += grid[r][j];
        }

        // Check all rows
        for (int i = r; i < r + k; i++) {
            int sum = 0;
            for (int j = c; j < c + k; j++) {
                sum += grid[i][j];
            }
            if (sum != target)
                return false;
        }

        // Check all columns
        for (int j = c; j < c + k; j++) {
            int sum = 0;
            for (int i = r; i < r + k; i++) {
                sum += grid[i][j];
            }
            if (sum != target)
                return false;
        }

        // Left diagonal
        int diag1 = 0;
        for (int i = 0; i < k; i++) {
            diag1 += grid[r + i][c + i];
        }
        if (diag1 != target)
            return false;

        // right diagonal
        int diag2 = 0;
        for (int i = 0; i < k; i++) {
            diag2 += grid[r + i][c + k - 1 - i];
        }
        if (diag2 != target)
            return false;
        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int max_sz = min(row, col);

        // Try Maxsize first

        for (int k = max_sz; k >= 1; k--) {
            for (int i = 0; i <= row - k; i++) {
                for (int j = 0; j <= col - k; j++) {
                    if (isMagic(grid, i, j, k)) {
                        return k;
                    }
                }
            }
        }
        return 1; // 1x1 is always magic
    }
};
