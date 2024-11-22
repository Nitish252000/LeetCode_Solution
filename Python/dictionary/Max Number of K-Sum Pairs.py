class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        mp={}
        cnt=0
        for i in range(len(nums)):
            comp = k-nums[i]
            if comp in mp and mp[comp]>0:
                mp[comp]-=1
                cnt+=1
            else:
                if nums[i] not in mp:
                    mp[nums[i]]=0
                mp[nums[i]]+=1
        return cnt
        
