class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) {
                    int row = i;
                    int col = j;

                    bool good = true;
                    // check in row
                    for (int c = 0; c < mat[0].size(); c++) {
                        if (mat[row][c] == 1 && c != col) {
                            good = false;
                            break;
                        }
                    }

                    // check in col
                    for (int r = 0; r < mat.size(); r++) {
                        if (mat[r][col] == 1 && r != row) {
                            good = false;
                            break;
                        }
                    }
                    if (good)
                        ans++;
                }
            }
        }
        return ans;
    }
};
