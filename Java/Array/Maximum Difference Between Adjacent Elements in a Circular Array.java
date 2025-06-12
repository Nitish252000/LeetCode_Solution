class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int n=nums.length;
        int diff=Integer.MIN_VALUE;
        for(int i=0;i<n-1;i++){
            diff=Math.max(diff,Math.abs(nums[i]-nums[i+1]));
        }
        return Math.max(diff,Math.abs(nums[0]-nums[n-1]));
    }
}
