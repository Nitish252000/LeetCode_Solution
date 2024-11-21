class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,vector<vector<int>>& walls) {
        // 0 = unoccupied, 1 = wall, 2 = guard, 3 = guarded
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (auto wall : walls) {
            grid[wall[0]][wall[1]] = 1; // mark wall
        }
        for (auto guard : guards) {
            grid[guard[0]][guard[1]] = 2; // Mark guard
        }

        vector<pair<int, int>> direct = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (const auto& guard : guards) {
            int x = guard[0], y = guard[1];
            for (const auto& dir : direct) {
                int nx = x + dir.first;  // Move in the row direction
                int ny = y + dir.second; // Move in the column direction

                // Check bounds and update grid if needed
                while (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if (grid[nx][ny] == 1 || grid[nx][ny] == 2)
                        break;        // Stop at wall or guard
                    grid[nx][ny] = 3; // Mark as guarded
                    nx += dir.first;  // Continue in the same direction
                    ny += dir.second;
                }
            }
        }
        int unguarded = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)unguarded++;
            }
        }
        return unguarded;
    }
};
