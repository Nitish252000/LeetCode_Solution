class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        // Right, Left, down, Top
        vector<vector<int>> dir = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // Try all 4 moves always

        vector<vector<int>> dist(
            rows, vector<int>(
                      cols, INT_MAX)); // Store minimum cost to reach each cell

        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        dist[0][0] = 0;

        // BFS loop: Keep exploring best path first
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            // Try all directions :Explore Neighbours
            for (int d = 0; d < 4; d++) {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];

                if (nx < 0 || ny < 0 || nx >= rows || ny >= cols) {
                    continue;
                }

                // cost = 0 if direction matches, else 1
                int cost = (grid[x][y] == d + 1) ? 0 : 1;
                if (dist[x][y] + cost < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + cost;

                    if (cost == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }
        return dist[rows - 1][cols - 1];
    }
};
