class Solution:
    def minimumLength(self, s: str) -> int:
        thisdict={}
        for i in s:
            thisdict[i]=thisdict.get(i,0)+1
        delcnt=0
        for val in thisdict.values():
            if val%2==1:
                delcnt+=val-1
            else:
                delcnt+=val-2
        return len(s)-delcnt
