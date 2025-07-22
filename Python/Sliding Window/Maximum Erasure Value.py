class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        left=0
        curr_sum=0
        max_sum=0
        seenSet=set()
        for right in range(0,len(nums)):
            while nums[right] in seenSet:
                seenSet.remove(nums[left])
                curr_sum-=nums[left]
                left+=1
            seenSet.add(nums[right])
            curr_sum+=nums[right]
            max_sum=max(max_sum,curr_sum)
        return max_sum
        
