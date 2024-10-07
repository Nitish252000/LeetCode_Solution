class Solution:
    def minLength(self, s: str) -> int:
        st=[]
        for i in range(len(s)):
            if len(st)!=0 and st[-1]=='A':
                if s[i]=='B':
                    st.pop()
                else: 
                    st.append(s[i])
            elif len(st)!=0 and st[-1]=='C':
                if s[i]=='D':
                    st.pop()
                else: 
                    st.append(s[i])
            else:
                st.append(s[i])
        return len(st)
