class Solution:
    def reformat(self, s: str) -> str:
        digit,letter,ans="","",""
        for i in s:
            if i.isdigit():
                digit+=i
            else:
                letter+=i
        if abs(len(letter)-len(digit)) >1:
            return ans
        startFirst=len(digit)>len(letter)
        l,d = 0,0
        while l<len(letter) or d<len(digit):
            if(startFirst and d<len(digit)):
                ans+=digit[d]
                d+=1
            else:
                ans+=letter[l]
                l+=1
            startFirst=not startFirst
        return ans
        
