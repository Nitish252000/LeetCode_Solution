class Solution:
    def digitSum(self,num:int) -> int:
        sum=0
        while num!=0:
            sum+=num%10
            num=num//10
        return sum
    def maximumSum(self, nums: List[int]) -> int:
        thisdict=defaultdict(list)
        for num in nums:
            thisdict[self.digitSum(num)].append(num)
        maxi=-1
        for sum_val,val in thisdict.items():
            if len(val)>1:
                val.sort(reverse=True)
                maxi=max(maxi,val[0]+val[1])
        return maxi
