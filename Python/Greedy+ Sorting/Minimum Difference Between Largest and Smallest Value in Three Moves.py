class Solution:
    def minDifference(self, nums: List[int]) -> int:
        n=len(nums)
        nums.sort()
        if n<=4:
            return 0
        mini = float(inf)
        mini=min(mini,nums[n-4]-nums[0])
        mini=min(mini,nums[n-1]-nums[3])
        mini=min(mini,nums[n-3]-nums[1])
        mini=min(mini,nums[n-2]-nums[2])
        return mini


# To assign int_min (the minimum possible integer value) and int_max (the maximum possible integer value) in Python, you can use float('-inf') and float('inf') respectively. However, if you prefer using an integer value, you can use the minimum and maximum values for a 32-bit signed integer, which are -2**31 and 2**31 - 1.
