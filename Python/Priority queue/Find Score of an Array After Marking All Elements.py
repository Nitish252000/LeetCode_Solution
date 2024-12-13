class Solution:
    def findScore(self, nums: List[int]) -> int:
        score =0
        n =len(nums)
        pq=[]
        track =n*[False]
        for i in range(n):
            heapq.heappush(pq,(nums[i],i))
        
        while pq:
            val,ind=heapq.heappop(pq)
            if track[ind]:
                continue
            score+=val
            track[ind]=True
            if ind>0:
                track[ind-1]=True
            if ind<n-1:
                track[ind+1]=True
        return score
