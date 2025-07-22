class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int curr_sum=0;
        int max_sum=Integer.MIN_VALUE;
        int left=0;
        HashSet<Integer> seen=new HashSet<>();
        for(int right=0;right<nums.length;right++){
            while(seen.contains(nums[right])){
                curr_sum-=nums[left];
                seen.remove(nums[left]);
                left++;
            }
            seen.add(nums[right]);
            curr_sum+=nums[right];
            max_sum=Math.max(max_sum,curr_sum);
        }
        return max_sum;
    }
}
