class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        pq=[]
        for num in nums:
            heapq.heappush(pq,num)

        total_operation=0
        while pq[0]<k:
            x=heapq.heappop(pq)
            y=heapq.heappop(pq)
            heapq.heappush(pq,min(x,y)*2+max(x,y))
            total_operation+=1
        return total_operation
        
