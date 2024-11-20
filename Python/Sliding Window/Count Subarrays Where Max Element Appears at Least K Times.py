class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        maxi = max(nums)
        left =0
        ans =0
        maxElemInWin = 0
        for right in range(0,len(nums)):
            if nums[right] ==maxi:
                maxElemInWin+=1
            while maxElemInWin == k:
                if nums[left] ==maxi:
                    maxElemInWin-=1
                left+=1
            ans+=left
        return ans

        
