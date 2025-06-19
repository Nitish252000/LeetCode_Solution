class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        cnt=0
        mini=nums[0]
        for i in range(len(nums)):
            if nums[i]-mini>k:
                cnt+=1
                mini=nums[i]
        return cnt+1
        
