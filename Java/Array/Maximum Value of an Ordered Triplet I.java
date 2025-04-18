class Solution {
    public long maximumTripletValue(int[] nums) {
        long val=0;
        for(int i=0;i<nums.length-2;i++){
            for(int j=i+1;j<nums.length-1;j++){
                for(int k=j+1;k<nums.length;k++){
                    long curr=(long)(nums[i] - nums[j]) * nums[k];
                    if(curr>val){
                        val=curr;
                    }
                }
            }
        }
        return val;
    }
}
