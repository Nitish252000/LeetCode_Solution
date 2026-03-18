class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;

        vector<vector<int>> prefix(rows, vector<int>(cols, 0));

        // Formula : prefix[r][c] = grid[r][c] + top + left - top-left overlap

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // Boundary Condition : first row and First column

                // Case 1: top-left corner
                if (r == 0 && c == 0) {
                    prefix[r][c] = grid[r][c];
                }
                // Case 2: First row
                else if (c > 0 && r == 0) {
                    prefix[r][c] = grid[r][c] + prefix[r][c - 1];
                }
                // Case 3: First Column
                else if (r > 0 && c == 0) {
                    prefix[r][c] = grid[r][c] + prefix[r - 1][c];
                }
                // Case 4: General Case
                else if (r > 0 && c > 0) {
                    prefix[r][c] = grid[r][c] + prefix[r - 1][c] +
                                   prefix[r][c - 1] - prefix[r - 1][c - 1];
                }
                if (prefix[r][c] <= k)
                    ans++;
            }
        }
        return ans;
    }
};
