class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        pq = []
        for i in range(len(nums)):
            heapq.heappush(pq,(nums[i],i))
        
        while k!=0:
            val,ind= heapq.heappop(pq)
            heapq.heappush(pq,(val*multiplier, ind))
            k-=1
        ans=len(nums)*[0]
        while pq:
            val,ind = heapq.heappop(pq)
            ans[ind]=val
        return ans
