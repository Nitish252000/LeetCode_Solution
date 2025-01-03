class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        prefSum=[]
        prefSum.append(nums[0])
        for i in range(1, len(nums)):
            prefSum.append(prefSum[i-1]+nums[i])
        cnt =0
        n =len(nums)
        for i in range(n-1):
            leftSum=prefSum[i]
            rightSum=prefSum[n-1]-prefSum[i]
            if leftSum>=rightSum:
                cnt+=1
        return cnt
            
        
