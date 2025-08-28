class Solution {
    public int[][] sortMatrix(int[][] grid) {
        int n = grid.length;
        for (int i = 0; i < n; i++) {
            ArrayList<Integer> temp = new ArrayList<>();
            for (int j = 0; j + i < n; j++) {
                temp.add(grid[j + i][j]);
            }
            temp.sort(Collections.reverseOrder());
            for (int j = 0; j + i < n; j++) {
                grid[i + j][j] = temp.get(j);
            }
        }
        for (int j = 1; j < n; j++) {
            ArrayList<Integer> temp = new ArrayList<>();
            for (int i = 0; i + j < n; i++) {
                temp.add(grid[i][i + j]);
            }
            Collections.sort(temp);
            for (int i = 0; i + j < n; i++) {
                grid[i][i + j] = temp.get(i);
            }
        }
        return grid;
    }
}
