class Solution {
    public int longestBalanced(int[] nums) {
        int n = nums.length;
        // int maxi = Integer.MIN_VALUE;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            HashSet<Integer> odd = new HashSet<>();
            HashSet<Integer> even = new HashSet<>();

            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0) {
                    even.add(nums[j]);
                } else {
                    odd.add(nums[j]);
                }

                if (odd.size() == even.size()) {
                    maxi = Math.max(maxi, j - i + 1);
                }
            }
        }
        return maxi;
    }
}
