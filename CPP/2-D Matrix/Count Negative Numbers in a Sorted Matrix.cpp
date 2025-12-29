class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // ------Brute force approach ---- T.C = O(n*m) -------------------
        // int ans = 0;
        // for (int i = 0; i < grid.size(); i++) {
        //     for (int j = 0; j < grid[0].size(); j++) {
        //         if (grid[i][j] < 0) {
        //             ans++;
        //         }
        //     }
        // }
        // return ans;

        // ----------StairCase Method: T.C= O(n+m) -------------

        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        int r = 0;
        int c = col - 1;
        while (r < row && c >= 0) {
            if (grid[r][c] < 0) {
                count += row - r;
                c--;
            } else {
                r++;
            }
        }
        return count;
    }
};
