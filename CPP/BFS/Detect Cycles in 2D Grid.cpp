class Solution {
public:
    // ------- Right, bottom, Left, Top  ----------
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid,
    //          vector<vector<bool>>& visited) {
    //     visited[x][y] = true;
    //     int rows = grid.size();
    //     int cols = grid[0].size();

    //     for (int d = 0; d < 4; d++) {
    //         int nx = x + dir[d][0];
    //         int ny = y + dir[d][1];

    //         if (nx < 0 || ny < 0 || nx >= rows || ny >= cols) { // Boundary
    //         check
    //             continue;
    //         }
    //         // Only move if same character
    //         if (grid[nx][ny] != grid[x][y]) {
    //             continue;
    //         }
    //         if (visited[nx][ny] && !(nx == px && ny == py))
    //             return true;
    //         if (!visited[nx][ny]) {
    //             if (dfs(nx, ny, x, y, grid, visited))
    //                 return true;
    //         }
    //     }
    //     return false;
    // }
    bool bfs(int i, int j, vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, pair<int, int>>> q;
        q.push({{i, j}, {-1, -1}});
        visited[i][j] = true;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int x = curr.first.first;
            int y = curr.first.second;
            int px = curr.second.first;
            int py = curr.second.second;

            for (int d=0;d<4;d++) {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                if (grid[nx][ny] != grid[x][y])
                    continue;

                if (nx == px && ny == py)
                    continue;

                if (visited[nx][ny])
                    return true;

                visited[nx][ny] = true;
                q.push({{nx, ny}, {x, y}});
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j]) {
                    // if (dfs(i, j, -1, -1, grid, visited)) {
                    if (bfs(i, j, grid, visited))
                        return true;
                }
            }
        }
        return false;
    }
};
