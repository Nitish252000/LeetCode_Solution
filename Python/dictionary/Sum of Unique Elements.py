class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        fq={}
        for i in nums:
            fq[i]=fq.get(i,0)+1
        sum=0
        for i in fq:
            if fq[i]==1:
                sum+=i
        return sum
        
