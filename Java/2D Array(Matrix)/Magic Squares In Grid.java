class Solution {
    private boolean check(int [][]grid, int r, int c){
        boolean[] seen = new boolean[10]; // Use size 10 : bcz seen has indices 0..8 
                                        // You access seen[num] where num can be 9 → ArrayIndexOutOfBoundsException
        for(int i=r;i<r+3; i++){
            for(int j=c;j<c+3;j++){
                int num = grid[i][j];
                if (num <= 0 || num > 9 || seen[num]==true) {
                    return false;
                }
                seen[num]=true;
            }
        }

        // fist diagonal sum
        int diag1 = grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];

        // second diagonal sum
        int diag2 = grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c];

        if (diag1 != diag2)
            return false;

        // Check row sum
        for (int i = r; i < r + 3; i++) {
            if (diag1 != grid[i][c] + grid[i][c + 1] + grid[i][c + 2])
                return false;
        }

        // Check col sum
        for (int i = c; i < c + 3; i++) {
            if (diag1 != grid[r][i] + grid[r + 1][i] + grid[r + 2][i])
                return false;
        }
        return true;
    }

    public int numMagicSquaresInside(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;

        if (row < 3 || col < 3)
            return 0;

        int ans = 0;
        for (int i = 0; i <= row - 3; i++) {
            for (int j = 0; j <= col - 3; j++) {
                if (check(grid, i, j))
                    ans++;
            }
        }
        return ans;
    }
}
