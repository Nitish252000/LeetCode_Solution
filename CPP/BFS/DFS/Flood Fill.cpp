class Solution {
public:
    //--- Right, bottom, left, Up ---------------
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void dfs(vector<vector<int>>& image, int i, int j, int color,
                int currVal) {
        int rows = image.size();
        int cols = image[0].size();
        image[i][j] = color;
        for (int d = 0; d < 4; d++) {
            int nr = i + dir[d][0];
            int nc = j + dir[d][1];

            if (nr >= 0 && nc >= 0 && nr < rows && nc < cols &&
                image[nr][nc] == currVal) {
                dfs(image, nr, nc, color, currVal);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int rows = image.size();
        int cols = image[0].size();
        int currVal = image[sr][sc];
        if (currVal == color) {
            return image;
        }
        dfs(image, sr, sc, color, currVal);
        return image;
    }
};
