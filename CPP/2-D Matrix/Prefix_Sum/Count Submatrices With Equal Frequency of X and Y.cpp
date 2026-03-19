class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Replace X-> 1 , Y->-1 and .->0
        // Create integer grid
        vector<vector<int>> mat(rows, vector<int>(cols, 0));
        vector<vector<int>> cntX(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 'X'){
                    mat[i][j] = 1;
                    cntX[i][j] = 1;
                }
                else if (grid[i][j] == 'Y')
                    mat[i][j] = -1;
                else
                    mat[i][j] = 0;
            }
        }
        // Create Prefix matrix for X count
        vector<vector<int>> prefixX(rows, vector<int>(cols, 0));
        // Create Prefix matrix;
        vector<vector<int>> prefix(rows, vector<int>(cols, 0));
        int ans = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 && j == 0) {
                    prefix[i][j] = mat[i][j];
                }
                // first row
                else if (i == 0 && j > 0) {
                    prefix[i][j] = mat[i][j] + prefix[i][j - 1];
                }
                // first col
                else if (j == 0 and i > 0) {
                    prefix[i][j] = mat[i][j] + prefix[i - 1][j];
                }
                // General Case
                else {
                    prefix[i][j] = mat[i][j] + prefix[i - 1][j] +
                                   prefix[i][j - 1] - prefix[i - 1][j - 1];
                }


                // Prefix sum for X Count
                if (i == 0 && j == 0) {
                    prefixX[i][j] = cntX[i][j];
                }
                // first row
                else if (i == 0 && j > 0) {
                    prefixX[i][j] = cntX[i][j] + prefixX[i][j - 1];
                }
                // first col
                else if (j == 0 and i > 0) {
                    prefixX[i][j] = cntX[i][j] + prefixX[i - 1][j];
                }
                // General Case
                else {
                    prefixX[i][j] = cntX[i][j] + prefixX[i - 1][j] +
                                   prefixX[i][j - 1] - prefixX[i - 1][j - 1];
                }


                // check both conditions
                if (prefix[i][j] == 0 && prefixX[i][j]>0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

// Approach
/*I first convert the grid into numbers: I treat 'X' as +1, 'Y' as -1, and '.' as 0. The idea is that if the number of 'X' and 'Y' are equal in a submatrix, their sum will become zero.

Then I build a prefix sum matrix, where each cell stores the sum from the top-left corner (0,0) to that cell. This helps me quickly check the sum of submatrices starting from (0,0).

While building this, I check if the sum at any cell is zero. If it is, it means that submatrix has equal 'X' and 'Y'.

But there is one more condition — the submatrix should have at least one 'X'. So I also keep another prefix matrix to count how many 'X' are there, and I only count it if there is at least one 'X'.

So overall, I use prefix sums to efficiently count valid submatrices starting from (0,0).*/
