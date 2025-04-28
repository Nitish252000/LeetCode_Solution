class Solution {
    public long countSubarrays(int[] nums, long k) {
        long cnt = 0, total = 0;
        int left = 0, right;
        for (right = 0; right < nums.length; right++) {
            total += nums[right];
            // Shrink the window only if it becomes invalid
            while (left <= right && total * (right - left + 1) >= k) {
                total -= nums[left];
                left++;
            }
            cnt += right - left + 1;
        }
        return cnt;
    }
}
