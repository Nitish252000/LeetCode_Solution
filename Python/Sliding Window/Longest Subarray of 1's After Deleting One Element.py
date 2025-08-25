class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        left = 0
        max_sub = 0
        zeros = 0
        for right in range(len(nums)):
            if nums[right] == 0:
                zeros += 1
            while zeros > 1:
                if nums[left] == 0:
                    zeros -= 1
                left += 1
            max_sub = max(max_sub, right - left)  # -1 bcz, we must delete one element
        return max_sub
