class Solution:
    def check(self, n:int)->int:
        pro=1
        while n!=0:
            pro*=n%10
            n=n//10
        return pro

    def smallestNumber(self, n: int, t: int) -> int:
        while self.check(n)%t!=0:
            n+=1
        return n
        
