class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols, 0));

        // dir: right, bottom , left, top
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                } else {
                    ans[i][j] = -1; // mark unvisited
                }
            }
        }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = dir[d][0] + i;
                int ny = dir[d][1] + j;
                if ((nx >= 0 && nx < rows) && (ny >= 0 && ny < cols) && ans[nx][ny] == -1) {
                    ans[nx][ny] = 1 + ans[i][j];
                    q.push({nx, ny});
                }
            }
        }
        return ans;
    }
};
