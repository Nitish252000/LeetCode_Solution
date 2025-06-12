class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        n=len(nums)
        diff= float('-inf')
        for i in range(n-1):
            diff=max(diff,abs(nums[i]-nums[i+1]))
        return max(abs(nums[0]-nums[n-1]),diff)

        
