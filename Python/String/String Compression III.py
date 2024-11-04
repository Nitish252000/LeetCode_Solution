class Solution:
    def compressedString(self, word: str) -> str:
        comp=[]
        n=len(word)
        i=0
        while i<n:
            cnt=0
            c=word[i]
            while i<n and c== word[i] and cnt<9:
                cnt+=1
                i+=1
            comp.append(str(cnt))
            comp.append(c)
        return "".join(comp)

        
