class Solution:
    def helper(self,n:int)->str:
        res=""
        while n!=0:
            bit=n&1
            res=str(bit)+res
            n=n>>1
        return res
    def hasAlternatingBits(self, n: int) -> bool:
        str=self.helper(n)
        for i in range(len(str)-1):
            if str[i]==str[i+1]:
                return False
        return True
        
