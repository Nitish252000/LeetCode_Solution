class Solution {
    public int repeatedNTimes(int[] nums) {
        int sz = nums.length;
        int n = sz/2;
        HashMap<Integer,Integer> mp = new HashMap<>();
        for(int num:nums){
            mp.put(num,mp.getOrDefault(num,0)+1);
        }
        for(int i:mp.keySet()){
            if(mp.get(i)==n){
                return i;
            }
        }
        return 0;
    }
}
