class Solution:
    def maxDifference(self, s: str) -> int:
        fq={}
        for ch in s:
            fq[ch]=fq.get(ch,0)+1
        
        xodd=0
        neven=len(s)
        for i in fq:
            if fq[i]%2==1:
                xodd=max(xodd,fq[i])
            else:
                neven=min(neven,fq[i])

        return xodd-neven
