class Solution:
    def clearDigits(self, s: str) -> str:
        st=[]
        for i in s:
            if len(st)!=0 and i.isdigit():
                st.pop()
            else:
                st.append(i)
        return "".join(st)
        
