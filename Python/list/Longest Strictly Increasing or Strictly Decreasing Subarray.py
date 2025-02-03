class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        maxl =0
        #Increasing
        for i in range(len(nums)):
            currl=1
            for j in range(i+1,len(nums)):
                if nums[j]>nums[j-1]:
                    currl+=1
                else:
                    break
            maxl=max(maxl,currl)
        
        #Decreasing
        for i in range(len(nums)):
            currl=1
            for j in range(i+1,len(nums)):
                if nums[j]<nums[j-1]:
                    currl+=1
                else:
                    break
            maxl=max(maxl,currl)
        return maxl
