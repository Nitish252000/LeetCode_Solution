class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int start = 0;
        int end = n - 1;
        // swap: row-wise
        while (start < end) {
            swap(matrix[start], matrix[end]);
            start++;
            end--;
        }
        // Transpose :
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int data = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = data;
            }
        }
    }
};
