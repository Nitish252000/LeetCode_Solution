class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        pq=[]
        for i in piles:
            heapq.heappush(pq,-i)
        stones=0
        while k>0:
            k-=1
            np = -heapq.heappop(pq)
            s=np -math.floor(np/2)
            heapq.heappush(pq,-s)
        sum=0
        for i in pq:
            sum+=-i
        return sum
        #return -sum(pq)
        
