class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        ans =0
        sum =0
        mp = {}
        n = len(nums)
        left =0
        for right in range (0, n):
            mp[nums[right]]=mp.get(nums[right],0)+1
            sum +=nums[right]

            ## if the window size exceed k, shrink the window
            while right-left+1>k:
                mp[nums[left]]-=1
                if mp[nums[left]]==0:
                    mp.pop(nums[left])
                sum-=nums[left]
                left+=1
            
            if right-left+1 == k and len(mp)==k:
                ans =max(ans,sum)
        return ans
