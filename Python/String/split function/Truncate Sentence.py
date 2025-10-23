class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        thislist=s.split()
        ans=""
        i=0
        while k!=0:
            ans+=thislist[i]+" "
            i+=1
            k-=1
        
        return ans.strip() # remove trailing space
