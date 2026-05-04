class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        reverse(mat.begin(), mat.end());
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        // at most 4 rotation: 0 deg, 90 deg, 180 deg, 270 deg
        for (int k = 0; k < 4; k++) { 
            if (mat == target)
                return true;
            rotate(mat);
        }
        return false;
    }
};
