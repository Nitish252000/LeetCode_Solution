class Solution:
    def minimumSteps(self, s: str) -> int:
        totalswap = 0
        white =0
        for i in range(len(s)):
            if s[i]=='0':
                totalswap+=i-white
                white+=1
            
        return totalswap
        
