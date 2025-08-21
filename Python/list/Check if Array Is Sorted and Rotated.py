class Solution:
    def check(self, nums: List[int]) -> bool:
        n=len(nums)
        cnt=0
        for i in range(n):
            if nums[i]>nums[(i+1)%n]:
                cnt+=1
        if cnt>1:
            return False
        return True


# 🔑 Concept

# An array is a sorted and rotated version of a non-decreasing array if at most one "drop" exists.

# A "drop" = a position where nums[i] > nums[i+1].

# If there are more than one drop, then it’s not sorted rotated.

# Special case: We also need to check the last and first element nums[n-1] > nums[0].


# 🔎 Explanation:

# Loop through array nums.

# Compare each element with the next (i+1) % n to wrap around.

# Count how many times the order breaks.

# If more than 1 break → return false, else return true.
