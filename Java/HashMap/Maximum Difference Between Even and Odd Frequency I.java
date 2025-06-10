class Solution {
    public int maxDifference(String s) {
        HashMap<Character,Integer> fq=new HashMap<>();
        for(char ch:s.toCharArray()){
            fq.put(ch,fq.getOrDefault(ch,0)+1);
        }
        int xodd=0;
        int neven=s.length();
        for(Integer i:fq.values()){
            if(i%2==1)xodd=Math.max(xodd,i);
            else
            neven=Math.min(neven,i);
        }
        return xodd-neven;
    }
}
