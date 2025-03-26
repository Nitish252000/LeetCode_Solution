class Solution {
    public int minOperations(int[][] grid, int x) {
        ArrayList<Integer> nums = new ArrayList<Integer>();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                nums.add(grid[i][j]);
            }
        }
        Collections.sort(nums);

        
        int base = nums.get(0);
        for (int i = 0; i < nums.size(); i++) {
            if (Math.abs(nums.get(i) - base) % x != 0)
                return -1;
        }
        int mid = nums.get(nums.size() / 2);
        int operation = 0;
        for (int num : nums) {
            operation += Math.abs(num - mid) / x;
        }
        return operation;
    }
}
