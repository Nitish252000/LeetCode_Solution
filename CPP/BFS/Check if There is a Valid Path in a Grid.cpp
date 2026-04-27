class Solution {
public:
    // Right, Bottom, Left, Top ------------------
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    // Allowed directions in each type
    vector<vector<int>> type = {{},     {2, 0}, {3, 1}, {2, 1},
                                {0, 1}, {2, 3}, {0, 3}};

    bool isConnect(int r, int c, int nr, int nc, vector<vector<int>>& grid) {
        for (int d : type[grid[nr][nc]]) {
            int br = nr + dir[d][0];
            int bc = nc + dir[d][1];
            if (br == r && bc == c)
                return true;
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = 1; // Mark visited
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            if (x == rows - 1 && y == cols - 1)
                return true;

            for (auto& d : type[grid[x][y]]) {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];

                // Check Boundry Condition:
                if ((nx >= 0 && ny >= 0 && nx < rows && ny < cols) &&
                    visited[nx][ny] == 0 && isConnect(x, y, nx, ny, grid)) {
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                }
            }
        }
        return false;
    }
};
