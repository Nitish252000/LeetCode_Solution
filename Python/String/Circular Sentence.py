class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        n =len(sentence)
        ans = True
        for i in range(n):
            if sentence[i]==' ' and i!=n-1:
                if sentence[i-1]!=sentence[i+1]:
                    ans=False
            if i==n-1:
                if sentence[i]!=sentence[0]:
                    ans=False
        return ans
