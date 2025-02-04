class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        maxi=0
        for i in range(len(nums)):
            currs=nums[i]
            for j in range(i+1,len(nums)):
                if nums[j]>nums[j-1]:
                    currs+=nums[j]
                else:
                    break
            maxi=max(maxi,currs)
        return maxi
        
