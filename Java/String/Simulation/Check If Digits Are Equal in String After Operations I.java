class Solution {
    public boolean hasSameDigits(String s) {
        int[] digits = new int[s.length()];
        for(int i=0;i<s.length();i++){
            digits[i]=s.charAt(i)-'0';
        }
        int len=digits.length;
        while(len>2){
            for(int i=0;i<len-1;i++){
                digits[i]=(digits[i]+digits[i+1])%10;
            }
            len--;
        }
        return digits[0]==digits[1];
    }
}
