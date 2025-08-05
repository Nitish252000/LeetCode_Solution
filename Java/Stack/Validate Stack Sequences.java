class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> st= new Stack<>();
        int poppedInd=0;
        for(int num:pushed){
            st.push(num);
            while(!st.isEmpty() && popped[poppedInd]==st.peek()){
                poppedInd++;
                st.pop();
            }
        }
        if(poppedInd==popped.length)return true;
        return false;
    }
}
