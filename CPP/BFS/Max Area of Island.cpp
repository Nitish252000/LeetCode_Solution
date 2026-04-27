class Solution {
public:
    // Right, Bottom, Left, Top -------------
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    // int dfs(int i, int j, vector<vector<int>>& grid,
    //         vector<vector<bool>>& visited) {
    //     int rows = grid.size();
    //     int cols = grid[0].size();
    //     visited[i][j]=true;
    //     int area = 1;
    //     for (int d = 0; d < 4; d++) {
    //         int nx = i + dir[d][0];
    //         int ny = j + dir[d][1];

    //         // check boundry
    //         if (nx < 0 || ny < 0 || nx >= rows || ny >= cols)
    //             continue;

    //         if (grid[nx][ny] == 0)
    //             continue;
    //         if (visited[nx][ny]==false && grid[nx][ny] == 1) {
    //             area +=dfs(nx, ny, grid, visited);
    //         }
    //     }
    //     return area;
    // }
    int bfs(int i,int j, vector<vector<int>>&grid, vector<vector<bool>>&visited){
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j]=true;
        int area = 1;
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int d=0;d<4;d++){
                int nr=r+dir[d][0];
                int nc=c+dir[d][1];

                if(nr<0 || nc<0 || nr>=rows || nc>=cols){
                    continue;
                }
                
                if(grid[nr][nc]==0)continue;

                if(visited[nr][nc]==false && grid[nr][nc]==1){
                    area+=1;
                    q.push({nr,nc});
                    visited[nr][nc]=true;
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int ans =0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (visited[i][j] == false && grid[i][j] == 1)
                    ans = max(ans, bfs(i,j,grid,visited));
            }
        }
        return ans;
    }
};
