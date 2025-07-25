class Solution {
    public int maxSum(int[] nums) {
        HashSet<Integer> st=new HashSet<>();
        for(int num:nums){
            if(num>0){
                st.add(num);
            }
        }
        if (st.size()==0){
            int maxi=Integer.MIN_VALUE;
            for(int num:nums){
                if(num>maxi)maxi=num;
            }
            return maxi;
        }
        int max_sum=0;
        for(Integer i:st)max_sum+=i;
        return max_sum;
    }
}
