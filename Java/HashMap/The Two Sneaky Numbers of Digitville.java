class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        HashMap<Integer,Integer> fq= new HashMap<>();
        for(int num:nums){
            fq.put(num,fq.getOrDefault(num,0)+1);
        }
        ArrayList<Integer> arr = new ArrayList<>();
        for(Integer i:fq.keySet()){
            if(fq.get(i)>1){
                arr.add(i);
            }
        }
        int sz=arr.size();
        int[] ans=new int[sz];
        int index=0;
        for(Integer i:arr){
            ans[index++]=i;
        }
        return ans;
    }
}
