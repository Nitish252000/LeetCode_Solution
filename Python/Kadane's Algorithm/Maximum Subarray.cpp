class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum=nums[0]
        maxi=nums[0]
        for i in range(1,len(nums)):
            sum = max(nums[i],nums[i]+sum)
            maxi= max(maxi,sum)
        return maxi
        
