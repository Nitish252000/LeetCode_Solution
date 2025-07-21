class Solution {
    public String makeFancyString(String s) {
        // Method 1: Stack Simulation
        // StringBuilder st= new StringBuilder();
        // for(char ch:s.toCharArray()){
        //     int sz= st.length();
        //     if(sz>=2 && st.charAt(sz-1)==ch && st.charAt(sz-2)==ch)
        //         continue;
        //     st.append(ch);
        // }
        // return st.toString();
        
        // Method 2: Frequencu Count 
        int fq=1;
        StringBuilder ans= new StringBuilder();
        ans.append(s.charAt(0));
        for(int i=1;i<s.length();i++){
            if(s.charAt(i)==s.charAt(i-1))fq++;
            else fq=1;
            if(fq<3)ans.append(s.charAt(i));
        }
        return ans.toString();
    }
}
