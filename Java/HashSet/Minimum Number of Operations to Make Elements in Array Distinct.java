class Solution {
    boolean check(int[] nums, int index){
        HashSet<Integer> st = new HashSet<>();
        for(int i=index;i<nums.length;i++){
            if(st.contains(nums[i]))return false;
            st.add(nums[i]);
        }
        return true;
    }
    public int minimumOperations(int[] nums) {
        int ans=0;
        for(int i=0;i<nums.length;i+=3){
            if(check(nums,i))break;
            ans++;
        }
        return ans;
    }
}
