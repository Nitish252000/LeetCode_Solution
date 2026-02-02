class Solution {
    public int[] separateDigits(int[] nums) {
        ArrayList<Integer> ans = new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            int num =nums[i];
            Stack<Integer> st = new Stack<>();
            if(num==0){
                st.push(0);
                continue;
            }
            while(num>0){
                st.push(num%10);
                num/=10;
            }

            while(!st.isEmpty()){
                ans.add(st.pop());
            }
        }
        int[] res = new int[ans.size()];
        for(int i=0;i<ans.size();i++){
            res[i]=ans.get(i);
        }
        return res;
    }
}
