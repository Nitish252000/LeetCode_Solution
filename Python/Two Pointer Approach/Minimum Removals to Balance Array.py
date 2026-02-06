class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()
        ans = n
        right = 0

        for left in range(n):
            while right < n and nums[right] <= k * nums[left]:
                right += 1
            ans = min(ans, n - (right - left))
        return ans
