class Solution(object):
    def isContainZero(self,n):
        while n>0:
            if n%10==0:
                return False
            n//=10
        return True
    
    def getNoZeroIntegers(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        for a in range(1,n):
            b=n-a
            if self.isContainZero(a) and self.isContainZero(b):
                return [a,b]
        return []
