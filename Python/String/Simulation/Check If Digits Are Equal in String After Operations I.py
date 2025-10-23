class Solution:
    def hasSameDigits(self, s: str) -> bool:
        digits=[]
        for i in s:
            digits.append(int(i))

        while len(digits)>2:
            for i in range(len(digits)-1):
                digits[i]=(digits[i]+digits[i+1])%10
            digits.pop()   # remove last element after combining
        return digits[0]==digits[1]
        
