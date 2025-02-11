class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        st=[]
        for ch in s:
            st.append(ch)
            if len(st)>=len(part) and self.check(st,part):
                for i in range(len(part)):
                    st.pop()
        return "".join(st)
    def check(self,st:list,part:str)->bool:
        n =len(part)
        for i in range(n):
            if st[-n+i]!=part[i]:
                return False
            # st.pop()
        return True
