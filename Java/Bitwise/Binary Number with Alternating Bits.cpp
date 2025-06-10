class Solution {
    String helper(int n){
        String res="";
        while(n!=0){
            int bit=n&1;
            res=Integer.toString(bit)+res;
            n=n>>1;
        }
        return res;
    }
    public boolean hasAlternatingBits(int n) {
        String str=helper(n);
        for(int i=0;i<str.length()-1;i++){
            if(str.charAt(i)==str.charAt(i+1)){
                return false;
            }
        }
        return true;
    }
}
