class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> original = mat;
        while (k != 0) {
            for (int i = 0; i < rows; i++) {
                if (i % 2 == 0) { // left shift
                    int first = mat[i][0];
                    for (int j = 0; j < cols-1; j++) {
                        mat[i][j] = mat[i][j + 1];
                    }
                    mat[i][cols - 1] = first;
                } else { // Right Shift
                    int last = mat[i][cols - 1];
                    for (int j = cols - 1; j > 0; j--) {
                        mat[i][j] = mat[i][j - 1];
                    }
                    mat[i][0] = last;
                }
            }
            k--;
        }
        return mat == original;
    }
};
