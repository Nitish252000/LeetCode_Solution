class NumMatrix {
public:
    // ----------------- Method 1: Will give TLE----------------
    // vector<vector<int>>mat;
    // NumMatrix(vector<vector<int>>& matrix) {
    //     this->mat=matrix;
    // }

    // int sumRegion(int row1, int col1, int row2, int col2) {
    //     int sum =0;
    //     for(int i=row1;i<=row2;i++){
    //         for(int j=col1;j<=col2;j++){
    //             sum+=mat[i][j];
    //         }
    //     }
    //     return sum;
    // }

    // ----- Method 2: Using Prefix Sum
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        prefix.assign(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefix[i][j] =
                    matrix[i][j]; // it will handle 1st element at (0, 0)
                if (i > 0) {
                    prefix[i][j] += prefix[i - 1][j];
                }
                if (j > 0) {
                    prefix[i][j] += prefix[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    prefix[i][j] -= prefix[i - 1][j - 1];
                }
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = prefix[row2][col2]; // big rectangle
        if (row1 > 0)
            sum -= prefix[row1 - 1][col2];
        if (col1 > 0)
            sum -= prefix[row2][col1 - 1];
        if (row1 > 0 && col1 > 0)
            sum += prefix[row1 - 1][col1 - 1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
