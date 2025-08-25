class Solution {
    public int longestSubarray(int[] nums) {
        int zeros=0;
        int max_sub=0;
        int left=0;
        for(int right=0;right<nums.length;right++){
            if(nums[right]==0){
                zeros++;
            }
            while(zeros>1){
                if(nums[left]==0)zeros--;
                left++;
            }
            max_sub=Math.max(max_sub,right-left); // -1 bcz, we must delete one element
        }
        return max_sub;
    }
}
