 vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> v(grid.size() - 2, vector<int>(grid.size() - 2));

        for (int i = 0; i < grid.size() - 2; i++) {
            for (int j = 0; j < grid[i].size() - 2; j++) {
                int maxi = INT_MIN;
                for (int ii = i; ii <= i + 2; ii++) {
                    for (int jj = j; jj <= j + 2; jj++) {
                        if (grid[ii][jj] > maxi)
                            maxi = grid[ii][jj];
                    }
                }
                v[i][j] = maxi;
            }
        }
        return v;
    }
