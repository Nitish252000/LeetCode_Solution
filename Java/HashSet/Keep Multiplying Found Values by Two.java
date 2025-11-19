class Solution {
    public int findFinalValue(int[] nums, int original) {
        HashSet<Integer> st=new HashSet<>();
        for(int num:nums)        {
            st.add(num);
        }
        int tar=original;
        while(st.contains(tar)){
            tar*=2;
        }
        return tar;
    }
}
